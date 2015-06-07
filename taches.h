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
#include "event.h"
#include "tachemanager.h"

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


#endif // TACHES

