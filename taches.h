#ifndef TACHES
#define TACHES
#include <QTextStream>
#include <QDate>
#include <QString>
#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QMessageBox>

#include "calendarexception.h"
#include "duree.h"
#include "mainwindow.h"

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

class Tache : public Event {
    /*! \class Tache
            \brief Classe permettant de définir des taches
    */
protected:
    QDate disponibilite;
    QDate echeance;
    bool preemptive;
    Tache(const QString& id, const QString& t, const Duree& dur, const QDate& dispo, const QDate& deadline, bool preempt=false): Event(id, t, dur),preemptive(preempt)
    {

        setDatesDisponibiliteEcheance(dispo, deadline);

    }
    friend class TacheManager;
public:
    //! Constructeur

    QString getId() const { return Event::getId(); }//<!Retourne l'identificateur
    void setId(const QString& str){
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id déjà existante");
        Event::setId(str);
    }

    QDate getDateDisponibilite() const {  return disponibilite; }//<!Retourne la disponibilité
    QDate getDateEcheance() const {  return echeance; }//<!Retourne l'echeance
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e) {//<!Définit la disponibilité et l'echeance en vérifiant que la première est bien inféreur a la seconde
        if (e<disp) throw CalendarException("erreur Tâche : date echéance < date disponibilité");
        disponibilite=disp; echeance=e;
    }
    bool isPreemptive() const { return preemptive; }//<!Retourne la préemptivité
    void setPreemptive() { preemptive=true; }//<!Défini la préemptivité
    void setNonPreemptive() { preemptive=false; }//<!Défini la préemptivité
    QString afficherTache();

};
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

////////////////////////////////////////////////Programmation des taches

class Programmation {
    friend class ProgrammationManager;
protected:

    const Tache* tache;
    QDate date;
    QTime horaire;
    QTime fin;
public:
    Programmation(const Tache& t, const QDate& d, const QTime& h, const QTime& f):tache(&t), date(d), horaire(h), fin(f){}
    const Tache& getTache() const { return *tache; }
    QDate getDate() const { return date; }
    QTime getHoraire() const { return horaire; }
    QTime getfin() const {return fin;}

};

class ProgrammationManager {
    friend class Programmation;
private:
    Programmation** programmations;
    unsigned int nb;
    unsigned int nbMax;
    static ProgrammationManager m_instance;

    void addItem(Programmation* t);
    Programmation* trouverProgrammation(const Tache& t) const;

    ProgrammationManager();
    ~ProgrammationManager();
    ProgrammationManager(const ProgrammationManager& um);
    ProgrammationManager& operator=(const ProgrammationManager& um);
public:

    void ajouterProgrammation(const Tache& t, const QDate& d, const QTime& h, const QTime& f);
    static ProgrammationManager& getInstance();

    class Iterator {
        friend class ProgrammationManager;
        Programmation** currentProg;
        unsigned int nbRemain;
        Iterator(Programmation** u, unsigned nb):currentProg(u),nbRemain(nb){}
    public:
        Iterator():nbRemain(0),currentProg(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw CalendarException("error, next on an iterator which is done");
            nbRemain--;
            currentProg++;
        }
        Programmation& current() const {
            if (isDone())
                throw CalendarException("error, indirection on an iterator which is done");
            return **currentProg;
        }
    };

    Iterator getIterator() {
        return Iterator(programmations,nb);
    }
};







#endif // TACHES

