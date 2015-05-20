#include "mainwindow.h"
#include "taches.h"

#include <QApplication>
#include <QFileDialog>
#include <QDate>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDate d (2015,7,2); QDate du (2016, 7, 1);
    Tache t("id", "titre", 600, d, du, false);
    //TacheManager &m = TacheManager::getInstance();
    TacheManager &m = TacheManager::getInstance();
    m.ajouterTache("id", "titre", 600, d, du, false);
    m.ajouterTache("id2", "titre2", 600, d, du, true);
    //w.MainWindow::afficher(t);
    w.show();

    return a.exec();
}
