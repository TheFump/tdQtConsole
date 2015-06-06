#include "projet.h"


 void Projet::setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e)
{//<!Définit la disponibilité et l'echeance en vérifiant que la première est bien inféreur a la seconde
    if (e<disp) throw CalendarException("erreur Tâche : date echéance < date disponibilité");
    disponibilite=disp; echeance=e;
}

 QString Projet::afficherProjet()
 {
     QString text;
     text.append("Description du porjet : \n");
     text.append("nom : " + getNom() + "\n");
     text.append("disponibilite : " + getDisponibilite().toString() + "\n");
     text.append("echeance : " + getEcheance().toString() + "\n");
     return text;
 }

/*Projet::~Projet()
{
    for(unsigned int i=0; i<nb; i++)
        delete tab[i];
    delete[] tab;
}*/
