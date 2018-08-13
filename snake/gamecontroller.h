#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#define MAX_LEVEL 4

#include <QObject>
#include <QMainWindow>
#include <QTimer>
#include <vector>

class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;
class Wall;

class GameController : public QObject
{
    Q_OBJECT
public:
    GameController(QGraphicsScene &scene, QObject *parent = 0, QMainWindow *mainWindow = 0);
    ~GameController();

    void snakeAteFood(Snake *snake, Food *food);
    void snakeHitWall(Snake *);
    void snakeAteItself(Snake *);
    void snakeLongEnough(Snake *);

    QMainWindow *mainWindow;

public slots:
    void pause();
    void resume();
    void nextLeval();
    void gameOver();
    void gamePass();
    void reDrawWall();

protected:
     bool eventFilter(QObject *object, QEvent *event);

private:
    void handleKeyPressed(QKeyEvent *event);
    void addNewFood();

    bool isPaused;
    int level;
    //int maxLevel;

    int speeds[MAX_LEVEL];

    QTimer timer;
    QGraphicsScene &scene;

    Snake *snake;
    Wall *wall;
};

#endif // GAMECONTROLLER_H
