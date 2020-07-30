#ifndef CUERPO_H
#define CUERPO_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPainter>

class cuerpo:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    double radio;
public:
    cuerpo(QGraphicsItem * parent=0);

    QRectF boundingRect() const; //dibujar un cuerpo
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //pintar el cuerpo


public slots:
    void move();
};

#endif // CUERPO_H
