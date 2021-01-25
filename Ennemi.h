#ifndef ENNEMI_H
#define ENNEMI_H

#include <string>
#include "PersonnageActif.h"
#include<stdlib.h>
#include<time.h>
#include"Item.h"

//Classe fille par rapport � PersonnageActif
//Classe m�re par rapport � Monstre, Bandit
class Ennemi :public PersonnageActif

{
 public:
 	
 	//Constructeur
    Ennemi(string nom,int echec);
    
    //M�thode virtuelle Pure permettant de retourner l'Item li� � l'ennemi que ce soit un monstre ou un bandit
    virtual Item &  recompense()=0;
    
    
 
 
    protected:
 	
 	//Probabilit� que l'ennemi �choue son attaque
    int tauxEchec;
    
    
};

#endif
