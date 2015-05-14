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

class Tache {
    /*! \class Duree
            \brief Classe permettant de d�finir des taches
    */
protected:
    QString identificateur;
    QString titre;
    Duree duree;
    QDate disponibilite;
    QDate echeance;
    bool preemptive;

    //friend class TacheManager;
public:
    //! Constructeur
    Tache(const QString& id, const QString& t, const Duree& dur, const QDate& dispo, const QDate& deadline, bool preempt=false):preemptive(preempt)
    {
        setId(id);
        setTitre(t);
        setDuree(dur);
        setDatesDisponibiliteEcheance(dispo, deadline);
    }
    QString getId() const { return identificateur; }//<!Retourne l'identificateur
    void setId(const QString& str){
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id d�j� existante");
        identificateur=str;
    }
    QString getTitre() const { return titre; }//<!Retourne le titre
    void setTitre(const QString& str) { titre=str; }//<!D�finir le titre
    Duree getDuree() const { return duree; }//<!Retourne la dur�e
    void setDuree(const Duree& d) { duree=d; }//<!D�fini la dur�e
    QDate getDateDisponibilite() const {  return disponibilite; }//<!Retourne la disponibilit�
    QDate getDateEcheance() const {  return echeance; }//<!Retourne l'echeance
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e) {//<!D�finit la disponibilit� et l'echeance en v�rifiant que la premi�re est bien inf�reur a la seconde
        if (e<disp) throw CalendarException("erreur T�che : date ech�ance < date disponibilit�");
        disponibilite=disp; echeance=e;
    }
    bool isPreemptive() const { return preemptive; }//<!Retourne la pr�emptivit�
    void setPreemptive() { preemptive=true; }//<!D�fini la pr�emptivit�
    void setNonPreemptive() { preemptive=false; }//<!D�fini la pr�emptivit�
    QString afficherTache();
};

class TacheManager {
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
    static TacheManager& getInstance();
    Tache& ajouterTache(const QString& id, const QString& t, const Duree& dur, const QDate& dispo, const QDate& deadline, bool preempt=false);
    Tache& getTache(const QString& id);
    bool isTacheExistante(const QString& id) const { return trouverTache(id)!=0; }
    const Tache& getTache(const QString& code) const;
    void load(const QString& f);
    void save(const QString& f);


};





#endif // TACHES

