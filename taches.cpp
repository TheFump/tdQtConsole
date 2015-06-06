#include "taches.h"


QTextStream &operator<<(QTextStream &f, const Tache &t)
{
    f<<t.getId()<<"\n";
        f<<t.getTitre()<<"\n";
        f<<t.getDuree()<<"\n";
        f<<t.getDateDisponibilite().toString()<<"\n";
        f<<t.getDateEcheance().toString()<<"\n";
        return f;

}

QString Tache::afficherTache()
{
    QString text;
    text.append("Description de la tache : \n");
    text.append("Identificateur : " + this->getId() + "\n");
    text.append("Titre : " + this->getTitre() + "\n");
    Duree d = this->getDuree();
    int x = d.getDureeEnMinutes();
    QString z;
    z.setNum(x);
    text.append("Duree : ");
    text.append(z);
    text.append("\n");
    text.append("Départ : " + this->getDateDisponibilite().toString("dd.MM.yyyy")+ "\n");
    text.append("Echeance : " + this->getDateEcheance().toString("dd.MM.yyyy")+ "\n");
    if(this->isPreemptive())
    text.append("Preemptive : true \n");
    else
    text.append("Preemptive : true \n");
    return text;
}












