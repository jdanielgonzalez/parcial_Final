#include "rectangulo.h"

rectangulo::rectangulo()
{

}

rectangulo::rectangulo(double x, double y)
{
    posx = x;
    posy =y;
    setPos(posx,posy);
}

QRectF rectangulo::boundingRect() const
{
    return QRectF(-largo/2,-ancho/2,largo,ancho);
}

void rectangulo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}

