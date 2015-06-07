#include "projetmanager.h"

ProjetManager::ProjetManager():projets(0),nb(0),nbMax(0){}

ProjetManager ProjetManager::m_instance = ProjetManager();

ProjetManager &ProjetManager::getInstance()
{
    return m_instance;
}

void ProjetManager::addItem(Projet* t){
    if (nb==nbMax){
        Projet** newtab=new Projet*[nbMax+10];
        for(unsigned int i=0; i<nb; i++) newtab[i]=projets[i];
        // ou memcpy(newtab,taches,nb*sizeof(Tache*));
        nbMax+=10;
        Projet** old=projets;
        projets=newtab;
        delete[] old;
    }
    projets[nb++]=t;
}

Projet* ProjetManager::trouverProjet(const QString& id)const{
    for(unsigned int i=0; i<nb; i++)
        if (id==projets[i]->getId()) return projets[i];
    return 0;
}

Projet& ProjetManager::ajouterProjet(const QString& id, const QString& t){
    if (trouverProjet(id)) throw CalendarException("erreur, ProjetManager, Projet deja existante");
    Projet* newt=new Projet(id,t);
    addItem(newt);
    return *newt;
}

Projet& ProjetManager::getProjet(const QString& id){
    Projet* t=trouverProjet(id);
    if (!t) throw CalendarException("erreur, ProjetManager, Projet inexistante");
    return *t;
}

/*const Projet& ProjetManager::getProjet(const QString& id)const{
    return const_cast<TacheManager*>(this)->getProjet(id);
}*/

ProjetManager::~ProjetManager(){
    //if (file!="") save(file);
    for(unsigned int i=0; i<nb; i++) delete projets[i];
    delete[] projets;
    file="";
}


void ProjetManager::viderProjet()
{
    for(unsigned int i=0; i<nb; i++) delete projets[i];
    delete[] projets;
}

void ProjetManager::ajouterTache(const QString &tid, const QString &pid)
{
    ProjetManager &p = ProjetManager::getInstance();
    TacheManager &m = TacheManager::getInstance();

    Projet h = p.getProjet(pid);
    Tache t = m.getTache(tid);
    h.addTache(&t);
}



