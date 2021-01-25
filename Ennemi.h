#ifndef ENNEMI_H
#define ENNEMI_H

#include <string>
#include "PersonnageActif.h"
#include<stdlib.h>
#include<time.h>
#include"Item.h"

//Classe fille par rapport à PersonnageActif
//Classe mère par rapport à Monstre, Bandit
class Ennemi :public PersonnageActif

{
 public:
 	
 	//Constructeur
    Ennemi(string nom,int echec);
    
    //Méthode virtuelle Pure permettant de retourner l'Item lié à l'ennemi que ce soit un monstre ou un bandit
    virtual Item &  recompense()=0;
    
    
 
 
    protected:
 	
 	//Probabilité que l'ennemi échoue son attaque
    int tauxEchec;
    
    
};

#endif
