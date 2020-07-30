#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene;
    timer = new QTimer;
    timermover = new QTimer;

    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,-398,390,390);
    escena->addRect(escena->sceneRect());
    connect(timer,SIGNAL(timeout()),this,SLOT(crear()));
    connect(timer,SIGNAL(timeout()),this,SLOT(crear()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_simular_clicked()
{
    timer->start(20);
}

void MainWindow::crear()
{
    int x = rand() % 1000;
    double y,v,a;
    y=500;
    v=20;
    a=0;
    double rad=(a/180)*3.1416;
    //pajaro = new cuerpo(x,y,v,rad);
    pajaros.push_back(new cuerpo(x,y,v,rad));
    escena->addItem(pajaros.back());
}

void MainWindow::mover()
{
    for(QList<cuerpo*>::iterator it= pajaros.begin(); it!=pajaros.end();it++)
    {
        (*it)->actualizarvelocidad();
        (*it)->actualizaposicion();
    }
}
