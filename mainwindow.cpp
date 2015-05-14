#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(afficherT(Tache& t)));
     QMetaObject::connectSlotsByName(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_printTache_clicked()
{
    //ui->Display->clear();
   // ui->Display->appendPlainText(t.Tache::afficherTache());
}


