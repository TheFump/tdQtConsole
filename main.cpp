#include "mainwindow.h"
#include"tachemanager.h"
#include "projet.h"
#include "projetmanager.h"

#include <iostream>
#include <QApplication>
#include <QFileDialog>
#include <QDate>
#include <QString>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    QDate d (2015,7,2); QDate du (2016, 7, 1);
    QTime t (2, 0); QTime t2(4, 0);
    //Tache t("id", "titre", 600, d, du, false);
    //TacheManager &m1 = TacheManager::getInstance();
    TacheManager &m = TacheManager::getInstance();
    m.ajouterTache("id", "titre", 600, d, du, false);
    m.ajouterTache("id2", "titre2", 600, d, du, true);
    Event e("id", "titre", 600);
   // ProgrammationManager &p = ProgrammationManager::getInstance();
    //p.ajouterProgrammation(m.getTache("id"), d, t, t2);
    w.update();
    //w.MainWindow::afficher(t);
    w.show();

    return a.exec();
    //todo corriger bug bouton programmationc

}
