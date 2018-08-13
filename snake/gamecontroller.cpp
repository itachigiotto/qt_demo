#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>

#include "gamecontroller.h"
#include "food.h"
#include "snake.h"
#include "wall.h"

static int num = 0;
static Food *a1 = NULL;

GameController::GameController(QGraphicsScene &scene, QObject *parent, QMainWindow *mainWindow) :
    QObject(parent),
    scene(scene),
    snake(new Snake(*this)),
    wall(new Wall(*this)),
    isPaused(false),
    level(0),
    mainWindow(mainWindow)
{
    speeds[0] = 8;
    speeds[1] = 4;
    speeds[2] = 2;
    speeds[3] = 1;

    timer.start( 1000/33 );

    mainWindow->setWindowTitle(QString("Snakes Love Eating: Level %1 : Speed = 1 / %2").arg(level + 1).arg(speeds[level]));

    scene.addItem(wall);

    Food *a1 = new Food(0, -50);
    scene.addItem(a1);

    scene.addItem(snake);
    scene.installEventFilter(this);

    resume();
}

GameController::~GameController()
{
}

void GameController::snakeAteFood(Snake *snake, Food *food)
{
    //    scene.removeItem(food);
    //    delete food;

    //    addNewFood();
    num ++;
    //snake->atenum ++;
    if (num == 1){
        scene.removeItem(food);
        delete(a1);
        //delete(wall);

        addNewFood();
    } else {
        scene.removeItem(food);
        delete food;
        //delete(wall);

        if (num == 10) {
            snakeLongEnough(snake);
        } else {
            addNewFood();
        }
    }
}

void GameController::snakeHitWall(Snake *)
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::snakeAteItself(Snake *)
{
    QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::snakeLongEnough(Snake *)
{
    if (level < MAX_LEVEL) {
        QTimer::singleShot(0, this, SLOT(nextLeval()));
    } else {
        QTimer::singleShot(0, this, SLOT(gamePass()));
    }
}

void GameController::handleKeyPressed(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        if (snake->getMoveDirection() != Snake::MoveRight) {
            snake->setMoveDirection(Snake::MoveLeft);
        }
        break;
    case Qt::Key_Right:
        if (snake->getMoveDirection() != Snake::MoveLeft) {
            snake->setMoveDirection(Snake::MoveRight);
        }
        break;
    case Qt::Key_Up:
        if (snake->getMoveDirection() != Snake::MoveDown) {
            snake->setMoveDirection(Snake::MoveUp);
        }
        break;
    case Qt::Key_Down:
        if(snake->getMoveDirection() != Snake::MoveUp) {
            snake->setMoveDirection(Snake::MoveDown);
        }
        break;
    case Qt::Key_Space:
        if (isPaused) {
            QTimer::singleShot(0, this, SLOT(resume()));
        } else {
            QTimer::singleShot(0, this, SLOT(pause()));
        }
    }
}

void GameController::addNewFood()
{
    int x, y;

    do {
        x = (int) ((qrand() % 200) - 100) / 10;
        y = (int) ((qrand() % 200) - 100) / 10;

        x *= 10;
        y *= 10;
    } while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));

    Food *food = new Food(x , y);
    scene.addItem(food);
    //QTimer::singleShot(0, this, SLOT(reDrawWall()));

}

void GameController::reDrawWall()
{
    delete(wall);
    Wall *wall = new Wall(*this);
    scene.addItem(wall);
}

void GameController::gameOver()
{
    scene.clear();

    snake = new Snake(*this);
    scene.addItem(snake);
    wall = new Wall(*this);
    scene.addItem(wall);
    addNewFood();
}

void GameController::gamePass()
{
    scene.clear();
    mainWindow->setWindowTitle(QString("Snakes Love Eating: You have passed this Game"));
    mainWindow->close();
}

void GameController::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               &scene, SLOT(advance()));
    isPaused = true;
}

void GameController::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
    isPaused = false;
}

void GameController::nextLeval()
{

    level ++;
    num = 0;
    scene.clear();
    mainWindow->setWindowTitle(QString("Snakes Love Eating: Level %1 : Speed = 1 / %2").arg(level + 1).arg(speeds[level]));
    snake = new Snake(*this);
    snake->setSpeed(speeds[level]);
    wall = new Wall(*this);
    scene.addItem(wall);
    scene.addItem(snake);
    addNewFood();
    //gamePass();
}

bool GameController::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
