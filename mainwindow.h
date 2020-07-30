#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "cuerpo.h"
#include <QGraphicsScene>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void aparecer_bolas();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *escena;

};
#endif // MAINWINDOW_H
