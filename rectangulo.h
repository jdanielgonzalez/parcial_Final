#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>

class rectangulo: public QGraphicsItem
{
    double posy,posx,largo=50,ancho=10;

public:
    rectangulo();
    rectangulo(double x, double y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGULO_H
