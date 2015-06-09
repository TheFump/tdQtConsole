#include "event.h"


int* Evt1j::afficher()
{
    int retour [8] = {0, 24, this->date.dayOfWeek()-1, this->date.dayOfWeek(), this->date.weekNumber(),this->date.weekNumber(), this->date.month(), this->date.year() };
    return retour;
}

int* EvtPj::afficher()
{
    int retour [8] = {0, 24, this->debut.dayOfWeek()-1, this->fin.dayOfWeek()-1, this->debut.weekNumber(),this->fin.weekNumber(), this->debut.month(), this->debut.year() };
    return retour;
}

int* Rdv::afficher()
{
    int * retour;
    retour = Evt1j::afficher();
    retour [0] = this->debut.hour();
    retour [1] = this->fin.hour();
    return retour;
}

