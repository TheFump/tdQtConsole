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
            \brief Classe permettant de d�finir des taches
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
        //if (TacheManager::getInstance().isTacheExistante((str))) throw CalendarException("erreur TacheManager : tache id d�j� existante");
        Event::setId(str);
    }

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


#endif // TACHES

