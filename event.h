#ifndef EVENT_H
#define EVENT_H

#include "duree.h"
#include <QString>

class Event {
protected:
    QString identificateur;
    QString titre;
    Duree duree;
public :
    Event(){}
    Event(const QString& id, const QString& t, const Duree& dur):identificateur(id), titre(t), duree(dur){}
    QString getId() const { return identificateur; }//<!Retourne l'identificateur
    void setId(const QString& str){
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id déjà existante");
        identificateur=str;
    }
    QString getTitre() const { return titre; }//<!Retourne le titre
    void setTitre(const QString& str) { titre=str; }//<!Définir le titre
    Duree getDuree() const { return duree; }//<!Retourne la durée
    void setDuree(const Duree& d) { duree=d; }//<!Défini la durée
};

#endif // EVENT_H
