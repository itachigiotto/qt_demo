#ifndef FOOD_H
#define FOOD_H
//#define TILE_SIZE 200
#include <QGraphicsItem>

class Food : public QGraphicsItem
{
public:
    Food(qreal x, qreal y);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QPainterPath shape() const;
};

#endif // FOOD_H
