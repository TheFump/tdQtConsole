#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include <QDate>
#include <QTime>
#include "calendarexception.h"

class Tache;
class Programmation;

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


#endif // PROGRAMMATIONMANAGER_H
