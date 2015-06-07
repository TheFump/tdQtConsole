#ifndef PROJETMANAGER
#define PROJETMANAGER
#include "projet.h"
#include "tachemanager.h"

class ProjetManager {
    friend class Projet;
private :
    Projet** projets;
    unsigned int nb;
    unsigned int nbMax;

    void addItem(Projet* t);
    Projet* trouverProjet(const QString& id) const;
    QString file;

    static ProjetManager m_instance;
    ~ProjetManager();
    ProjetManager& operator= (ProjetManager& t);
    ProjetManager();
public :
    static ProjetManager& getInstance();//<! Retourne instance tachemanager
    Projet& ajouterProjet(const QString& id, const QString& t);//<! ajoute une tahce �  l'appli
    Projet& getProjet(const QString& id);//<! retourne une tache via son id
    bool isProjetExistant(const QString& id) const { return trouverProjet(id)!=0; }//retourne l'existance d'une tahce
    const Projet& getProjet(const QString& code) const;//<! récupère une tahce via code

    void viderProjet();//<! vide les taches

    void ajouterTache(const QString& tid, const QString& pid);

};

#endif // PROJETMANAGER

