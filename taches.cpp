#include "taches.h"

Tache::Tache(const QString& id, const QString& t, const Duree& dur, const QDate& dispo, const QDate& deadline, bool preempt)
    : Event(id, t, dur),preemptive(preempt)
{
    setDatesDisponibiliteEcheance(dispo, deadline);
}

void Tache::setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e)
{//<!D�finit la disponibilit� et l'echeance en v�rifiant que la premi�re est bien inf�reur a la seconde
    if (e<disp) throw CalendarException("erreur T�che : date ech�ance < date disponibilit�");
    disponibilite=disp; echeance=e;
}

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
    text.append("D�part : " + this->getDateDisponibilite().toString("dd.MM.yyyy")+ "\n");
    text.append("Echeance : " + this->getDateEcheance().toString("dd.MM.yyyy")+ "\n");
    if(this->isPreemptive())
    text.append("Preemptive : true \n");
    else
    text.append("Preemptive : true \n");
    return text;
}












