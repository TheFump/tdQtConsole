#ifndef PROJET_H
#define PROJET_H
#include "taches.h"
#include "projetmanager.h"

class Projet {
protected:
    QString identificateur;
    QString titre;

    Tache** taches;
    unsigned int nb;
    unsigned int nbMax;

public :
    Projet(){}
    Projet(const QString& id, const QString& t):identificateur(id), titre(t), nb(0), nbMax(0), taches(0){}
    QString getId() const { return identificateur; }//<!Retourne l'identificateur
    void setId(const QString& str){
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id déj�  existante");
        identificateur=str;
    }
    QString getTitre() const { return titre; }//<!Retourne le titre
    void setTitre(const QString& str) { titre=str; }//<!Définir le titre

    void addTache(Tache* t);



};


#endif // PROJET_H

