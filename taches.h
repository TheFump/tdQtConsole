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

/*! \class Tache
        \brief Classe permettant de définir des taches
*/
class Tache : public Event {

    friend class TacheManager;

protected:
    QDate disponibilite;
    QDate echeance;
    bool preemptive;
    Tache(const QString& id, const QString& t, const Duree& dur, const QDate& dispo, const QDate& deadline, bool preempt=false);

public:
    //! Constructeur

    QString getId() const { return Event::getId(); }//<!Retourne l'identificateur
    void setId(const QString& str){
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id déjà existante");
        Event::setId(str);
    }

    QDate getDateDisponibilite() const {  return disponibilite; }//<!Retourne la disponibilité
    QDate getDateEcheance() const {  return echeance; }//<!Retourne l'echeance
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e);
    bool isPreemptive() const { return preemptive; }//<!Retourne la préemptivité
    void setPreemptive() { preemptive=true; }//<!Défini la préemptivité
    void setNonPreemptive() { preemptive=false; }//<!Défini la préemptivité
    QString afficherTache();

};


#endif // TACHES

