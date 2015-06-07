#include "mainwindow.h"
#include "tachemanager.h"
#include "programmation.h"
#include "programmationmanager.h"
#include "ui_mainwindow.h"
#include "projetmanager.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(afficherT(Tache& t)));
    //QMetaObject::connectSlotsByName(this);

    ui->Calendar->setRowCount(24);
    ui->Calendar->setColumnCount(7);

    QStringList days;
    days << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    ui->Calendar->setHorizontalHeaderLabels(days);
    QStringList hours;
    hours << "00h00" << "01h00" << "02h00" << "03h00" <<  "04h00" << "05h00" << "06h00" << "07h00" << "08h00" << "09h00" << "10h00" << "11h00" << "12h00" << "13h00" << "14h00" << "15h00" << "16h00" << "17h00" << "18h00" << "19h00" << "20h00" << "21h00" << "22h00" << "23h00" << "24h00";
    ui->Calendar->setVerticalHeaderLabels(hours);
    for(int i =0; i < 24; i++){
        for(int j =0; j < 7; j++){
            ui->Calendar->setItem(i, j, new QTableWidgetItem);

        }
    }
    ui->CalendarDate->setDate(QDate::currentDate());

}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::update()
{
  MainWindow::afficherCalendar();
}

void MainWindow::afficherCalendar()
{
    ProgrammationManager &p = ProgrammationManager::getInstance();
    ProgrammationManager::Iterator i = p.getIterator();
    QDate comp = ui->CalendarDate->date();
    while(!i.isDone()){
        if(i.current().getDate().weekNumber() == comp.weekNumber() ){
            if(i.current().getDate().year() == comp. year()){
        MainWindow::displayProgrammation(i.current());

            }
    }
    i.next();}
}

void MainWindow::displayProgrammation(const Programmation &p)
{
    int date = p.getDate().dayOfWeek();
    int i=0;
    for( i = p.getHoraire().toString("h").toInt(); i <p.getfin().toString("h").toInt(); i++)
    {
        ui->Calendar->item(i, date)->setBackgroundColor(Qt::gray);
    }
}




void MainWindow::on_printTache_clicked()
{
    ui->Display->clear();
    TacheManager &m = TacheManager::getInstance();
    ui->Display->appendPlainText(m.getTache(ui->tacheId->text()).Tache::afficherTache());
    update();
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
     update();
    }
}

void MainWindow::on_ajouterProjet_pressed()
{
    ProjetManager &p = ProjetManager::getInstance();
    p.ajouterProjet(ui->id->text(), ui->titre->text());
}

void MainWindow::on_addtachetoproject_clicked()
{
    ProjetManager &p = ProjetManager::getInstance();

    p.ajouterTache(ui->tacheId->text(), ui->projetId->text());
}


void MainWindow::on_MainWindow_quit()
{
    TacheManager &m = TacheManager::getInstance();
    m.viderTaches();
}

void MainWindow::on_addProg_clicked()
{
    ProgrammationManager &p = ProgrammationManager::getInstance();
    TacheManager &m = TacheManager::getInstance();
    p.ajouterProgrammation(m.getTache(ui->progId->text()), ui->progDate->date(), ui->progHoraire->time(), ui->Progfin->time());
    this->update();
}

void MainWindow::on_CalendarNext_clicked()
{
    ui->CalendarDate->setDate(ui->CalendarDate->date().addDays(7));
    this->update();
}

void MainWindow::on_CalendarPrevious_clicked()
{
    ui->CalendarDate->setDate(ui->CalendarDate->date().addDays(-7));
    this->update();

}


//*********************************************************************CalendarWidgget***********************************************************************************



