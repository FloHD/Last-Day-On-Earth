#ifndef BANDIT_H
#define BANDIT_H

#include <string>
#include "Ennemi.h"
#include "Weapon.h"
#include "Item.h"
#include <iostream>


using namespace std;

//Classe fille par rapport à Ennemi
class Bandit: public Ennemi 

{
 public:
 
 	//Constructeur
    Bandit(string nom);
    
    //redefintion pour la gestion de l'attaque par rapport à un autre personnage
    void attaquer(PersonnageActif & p);
    
    //affichage des informations definissant le bandit 
    void display();
    
    //redefiniton pour l'envoi de l'item ici un weapon
    Item & recompense();
   
    
 
 
    protected:
 
 	//Arme lié de l'ennemi qui sera envoyé au joueur en cas de victoire d'un combat notemment
    Weapon w; 
    
    
};


#endif
