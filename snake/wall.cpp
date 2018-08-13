#include <QPainter>

#include "gamecontroller.h"
#include "constants.h"
#include "wall.h"

static const qreal WALL_SIZE = 4;

Wall::Wall(GameController &controller) :
    controller(controller)
{
}

QRectF Wall::boundingRect() const
{
    QRectF bound = QRectF(-100, -100,
                           100,  100);
    return bound;
}

QPainterPath Wall::shape() const
{
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(-100,
                        -100,
                         200 - WALL_SIZE,
                         WALL_SIZE));
    path.addRect(QRectF( 100 - WALL_SIZE,
                        -100,
                         WALL_SIZE,
                         200 - WALL_SIZE));
    path.addRect(QRectF(-100 + WALL_SIZE,
                         100 - WALL_SIZE,
                         200 - WALL_SIZE,
                         WALL_SIZE));
    path.addRect(QRectF(-100,
                        -100 + WALL_SIZE,
                         WALL_SIZE,
                         200 - WALL_SIZE));
    return path;

}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->fillPath(shape(), Qt::black);
    painter->restore();
}
