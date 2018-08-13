#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>
#include <QRectF>

class GameController;

class Wall : public QGraphicsItem
{
public:
    Wall(GameController & controller);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QList<QPointF> body;
    GameController  &controller;
};

#endif // WALL_H
