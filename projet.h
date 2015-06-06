#ifndef PROJET_H
#define PROJET_H

#include <QString>
#include <QDate>

#include "calendarexception.h"

class Tache;

class Projet
{
public:

    QString afficherProjet();

    QString& getNom() { return nom; }
    QDate getDisponibilite() const { return disponibilite; }
    QDate getEcheance() const { return echeance; }
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e);
private:
    QString nom;
    QDate disponibilite;
    QDate echeance;
    //Il faut une table de projet qui sera maintenu a jour
    //Tache** tab;

    Projet(const QString& n):nom(n),disponibilite(QDate::currentDate()),echeance(QDate::currentDate()) {}
    ~Projet();
};

#endif // PROJET_H
