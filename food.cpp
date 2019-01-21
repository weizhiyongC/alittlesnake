#include <QPainter>

#include "constants.h"
#include "food.h"

static const qreal FOOD_RADIUS = 3;   //浮点型数据常量食物半径

Food::Food(qreal x, qreal y)    //定义食物
{
    setPos(x, y);               //定义坐标
    setData(GD_Type, GO_Food);  //该图形元素添加额外的数据信息
}

QRectF Food::boundingRect() const
{
                                //以（x，y）为中心，长度2倍的矩形
    return QRectF(-TILE_SIZE,    -TILE_SIZE,
                   TILE_SIZE * 2, TILE_SIZE * 2 );

}

void Food::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save(); //保存画笔状态

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red); //填充给定的画笔路径

    painter->restore();
}

QPainterPath Food::shape() const      //原始函数为虚函数，在此进行重写
{                                     //定义一个画笔路径
    QPainterPath p;
                    //添加绘制椭圆，（圆心，直径）
    p.addEllipse(QPointF(TILE_SIZE / 2, TILE_SIZE / 2), FOOD_RADIUS, FOOD_RADIUS);
    return p;
}
