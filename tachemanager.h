#ifndef TACHEMANAGER_H
#define TACHEMANAGER_H

#include "taches.h"
#include "duree.h"
#include <QDate>
#include <QString>

/** \class TacheManager
 * @brief The TacheManager class : gestion des classes
 */
class TacheManager {
    friend class Tache;
private :
    Tache** taches;
    unsigned int nb;
    unsigned int nbMax;
    void addItem(Tache* t);
    Tache* trouverTache(const QString& id) const;
    QString file;

    static TacheManager m_instance;
    ~TacheManager();
    TacheManager& operator= (TacheManager& t);
    TacheManager();
public :
    static TacheManager& getInstance();//<! Retourne instance tachemanager
    Tache& ajouterTache(const QString& id, const QString& t, const Duree& dur, const QDate& dispo, const QDate& deadline, bool preempt=false);//<! ajoute une tahce à l'appli
    Tache& getTache(const QString& id);//<! retourne une tache via son id
    bool isTacheExistante(const QString& id) const { return trouverTache(id)!=0; }//retourne l'existance d'une tahce
    const Tache& getTache(const QString& code) const;//<! récupère une tahce via code
    void load(const QString& f); //<! enregistre l'état des taches
    void save(const QString& f); //charge les taches
    void viderTaches();//<! vide les taches

    class Iterator {
        friend class TacheManager;
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
#endif // TACHEMANAGER_H
