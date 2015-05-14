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
            \brief Classe permettant de définir des taches
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
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id déjà existante");
        identificateur=str;
    }
    QString getTitre() const { return titre; }//<!Retourne le titre
    void setTitre(const QString& str) { titre=str; }//<!Définir le titre
    Duree getDuree() const { return duree; }//<!Retourne la durée
    void setDuree(const Duree& d) { duree=d; }//<!Défini la durée
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

