#ifndef PERSONNAGEACTIF_H 
#define PERSONNAGEACTIF_H

#include <string>
#include "Personnage.h"

using namespace std;

//Classe fille par rapport � Personnage
//Classe m�re par rapport � Joueur, Ennemi , Monstre, Bandit
class PersonnageActif :public Personnage

{
 public:
 	
 	//Constructeurs
    PersonnageActif(string nom,int life,int attaque);
    PersonnageActif(string nom);
    
    //M�thode virtuelle pure pour la gestion des attaques
    virtual void attaquer(PersonnageActif & p)=0;
    
    //M�thode  virtuelle pure pour l'affichage des donn�es du personnages
    virtual void display()=0;
    
    
    //Op�rateut de comparaison
    bool operator>(PersonnageActif & p2);
    
    
    //Setteurs pour les attibuts
	void setMort(int nbre);
    void setLife(int nbre);
    
	//Getteurs pour les attributs
	int getLife();
    int getMort();
    int getAttaque();
    
    
    
 
 
    protected:
 	
 	// vie du personnage
    int life;
    
    //entier pour savoir si le perso est mort (0==> vivant et 1==> mort)
    int mort;
    
    //puissance de base du personnage
    int attaque; 
    
    
};

#endif
