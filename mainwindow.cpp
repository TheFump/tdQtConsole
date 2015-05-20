#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(afficherT(Tache& t)));
    QMetaObject::connectSlotsByName(this);

    ui->Calendar->setRowCount(12);
    ui->Calendar->setColumnCount(7);

    QStringList days;
    days << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    ui->Calendar->setHorizontalHeaderLabels(days);
    QStringList hours;
    hours << "00h00" << "02h00" << "04h00" << "06h00" << "08h00" << "10h00" << "12h00" << "14h00" << "16h00"<< "18h00" << "20h00" << "22h00" << "24h00";
    ui->Calendar->setVerticalHeaderLabels(hours);



}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::update()
{

}

void MainWindow::on_printTache_clicked()
{
    ui->Display->clear();
    TacheManager &m = TacheManager::getInstance();
    ui->Display->appendPlainText(m.getTache(ui->tacheId->text()).Tache::afficherTache());
    update;
}

void MainWindow::on_ajouterTache_pressed()
{
    TacheManager &m = TacheManager::getInstance();
    Duree d = ui->duree->value();

    if(ui->preempt->isChecked() == false && d.getDureeEnHeures() >= 12)
    {
        QMessageBox::warning(this, "error", "Duree > 12");

    }
    else{
    if(ui->preempt->isChecked() && ui->composite->isChecked()){
        m.TacheManager::ajouterTache(ui->id->text(), ui->titre->text(), ui->duree->value(), ui->debut->date(), ui->fin->date(), true);
    }
    else   if(ui->preempt->isChecked() && !ui->composite->isChecked()){
        m.TacheManager::ajouterTache(ui->id->text(), ui->titre->text(), ui->duree->value(), ui->debut->date(), ui->fin->date(), true);
    }
    else   if(!ui->preempt->isChecked() && ui->composite->isChecked()){
        m.TacheManager::ajouterTache(ui->id->text(), ui->titre->text(), ui->duree->value(), ui->debut->date(), ui->fin->date(), false);
    }
    else   if(!ui->preempt->isChecked() && !ui->composite->isChecked()){
        m.TacheManager::ajouterTache(ui->id->text(), ui->titre->text(), ui->duree->value(), ui->debut->date(), ui->fin->date(), false);
    }
     ui->Display->clear();
     ui->Display->appendPlainText(m.getTache(ui->id->text()).Tache::afficherTache());
     update;
    }
}

void MainWindow::on_MainWindow_quit()
{
    TacheManager &m = TacheManager::getInstance();
    m.viderTaches();
}

//*********************************************************************CalendarWidgget***********************************************************************************



