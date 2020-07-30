#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QTimer>
#include "cuerpo.h"
#include <QList>

#include <QMainWindow>

namespace Ui { class MainWindow; }


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_simular_clicked();
    void crear();
    void mover();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer * timer;
    QTimer * timermover;
    cuerpo *pajaro;
    QList<cuerpo*> pajaros;


};
#endif // MAINWINDOW_H
