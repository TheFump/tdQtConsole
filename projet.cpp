#include "projet.h"


void Projet::addTache(Tache *t)
{
    if (nb==nbMax){
        //BUG IS HERE
        Tache** newtab=new Tache*[nbMax+10];
        for(unsigned int i=0; i<nb; i++) newtab[i]=taches[i];
        // ou memcpy(newtab,taches,nb*sizeof(Tache*));
        nbMax+=10;
        Tache** old=taches;
        taches=newtab;
        delete[] old;
    }
    taches[nb]=t;
    nb++;
}
