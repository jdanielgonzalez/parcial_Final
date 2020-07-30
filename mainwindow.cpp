#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,600,600); //darle un tamaño a la escena

    timer = new QTimer;
    timermover = new QTimer;
    timerectangulo = new QTimer;

    ui->graphicsView->setScene(escena);
    connect(timer,SIGNAL(timeout()),this,SLOT(crear()));
    connect(timerectangulo,SIGNAL(timeout()),this,SLOT(crear_rectangulo()));
    connect(timermover,SIGNAL(timeout()),this,SLOT(mover()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_simular_clicked()
{
    timer->start(2000);
    timerectangulo->start(4000);
    timermover->start(20);
}

void MainWindow::crear()
{
    int x = rand() % 600;
    int v =rand() % 30;
    int a = rand() % 45;
    double rad=(a/180)*3.1416;
    pajaros.push_back(new cuerpo(x,0,v,rad));
    escena->addItem(pajaros.back());
}

void MainWindow::mover()
{
    for(QList<cuerpo*>::iterator it= pajaros.begin(); it!=pajaros.end();it++)
    {

        for(QList<rectangulo*>::iterator ite= rectangulos.begin(); ite!=rectangulos.end();ite++)
        {
            if((*it)->collidesWithItem((*ite)))
            {
                (*it)->rebote();
            }
        }
        if((*it)->getPosy()<-600)
        {
            (*it)->hide();
        }
        if((*it)->getPosx()<0)
        {
            (*it)->rebote();
        }
        if((*it)->getPosx()>600)
        {
            (*it)->rebote();
        }
        (*it)->actualizarvelocidad();
        (*it)->actualizaposicion();
    }
}

void MainWindow::crear_rectangulo()
{
    int x = rand() % 600;
    int y =rand() % 30;
    rectangulos.push_back(new rectangulo(x,y));
    escena->addItem(rectangulos.back());
}
