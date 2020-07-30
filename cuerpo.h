#ifndef CUERPO_H
#define CUERPO_H
#include <math.h>
#include <QGraphicsItem>
#include <QPainter>

class cuerpo: public QGraphicsItem
{
    double g=9.8;
    double delta=0.1;
    double posy,posx,ang,vel,velx,vely;
    int r;

public:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    cuerpo();
    cuerpo(double x, double y, double v, double a);
    double getPosy();
    double getPosx();
    void actualizaposicion();
    void actualizarvelocidad();
    void rebote();

};

#endif // CUERPO_H
