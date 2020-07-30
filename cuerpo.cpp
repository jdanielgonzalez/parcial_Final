#include "cuerpo.h"

QRectF cuerpo::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

cuerpo::cuerpo()
{

}

double cuerpo::getPosy()
{
    return posy;
}

double cuerpo::getPosx()
{
    return posx;
}

void cuerpo::actualizaposicion()
{
    posx=posx+velx*delta;
    posy=posy+vely*delta-(0.5*g*delta*delta);
    setPos(posx,-posy);

}

void cuerpo::actualizarvelocidad()
{
    velx=vel*cos(ang);
    vely=vel*sin(ang)-g*delta;
    ang=atan2(vely,velx);
    vel=sqrt(velx*velx+vely*vely);
}

void cuerpo::rebote()
{
    vel=-vel;
}

cuerpo::cuerpo(double x, double y, double v, double a)
{
    r=15;
    posx = x;
    posy =y;
    vel=v;
    ang=a;
    setPos(posx,posy);
}
