#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene; //crear la escena del juego
    ui->graphicsView->setScene(escena); //agregar el graphicsView
    escena->setSceneRect(0,0,1000,698); //darle un tamaño a la escena

    cuerpo * bola = new cuerpo();
    escena->addItem(bola);

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(aparecer_bolas()));
    timer->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::aparecer_bolas()
{
    cuerpo * bola = new cuerpo();
    escena->addItem(bola);
}

