#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>

class Food : public QGraphicsItem
{
public:
    Food(qreal x, qreal y);    //构造函数，定义食物
    
    QRectF boundingRect() const;  //

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QPainterPath shape()  const;  //原始函数为虚函数，重写
};

#endif // FOOD_H
