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
        \brief Classe permettant de d�finir des taches
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
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id d�j� existante");
        Event::setId(str);
    }

    QDate getDateDisponibilite() const {  return disponibilite; }//<!Retourne la disponibilit�
    QDate getDateEcheance() const {  return echeance; }//<!Retourne l'echeance
    void setDatesDisponibiliteEcheance(const QDate& disp, const QDate& e);
    bool isPreemptive() const { return preemptive; }//<!Retourne la pr�emptivit�
    void setPreemptive() { preemptive=true; }//<!D�fini la pr�emptivit�
    void setNonPreemptive() { preemptive=false; }//<!D�fini la pr�emptivit�
    QString afficherTache();

};


#endif // TACHES

