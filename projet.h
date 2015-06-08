#ifndef PROJET_H
#define PROJET_H
#include "taches.h"
#include "projetmanager.h"

class Projet {
    friend class ProjetManager;
protected:
    QString identificateur;
    QString titre;

    Tache** taches;
    unsigned int nb;
    unsigned int nbMax;

    Projet(){}
    Projet(const QString& id, const QString& t):identificateur(id), titre(t), nb(0), nbMax(0), taches(0){}
public :

    QString getId() const { return identificateur; }//<!Retourne l'identificateur
    void setId(const QString& str){
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id déj�  existante");
        identificateur=str;
    }
    QString getTitre() const { return titre; }//<!Retourne le titre
    void setTitre(const QString& str) { titre=str; }//<!Définir le titre

    void addTache(Tache* t);

    class Iterator {
        friend class Projet;
        Tache** currentTache;
        unsigned int nbRemain;
        Iterator(Tache** u, unsigned nb):currentTache(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentTache(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw CalendarException("error, next on an iterator which is done");
            nbRemain--;
            currentTache++;
        }
        Tache& current() const {
            if (isDone())
                throw CalendarException("error, indirection on an iterator which is done");
            return **currentTache;
        }
    };

    Iterator getIterator() {
        return Iterator(taches,nb);
    }



};


#endif // PROJET_H

