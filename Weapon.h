#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"
#include <iostream>


class Weapon : public Item

{
 public:
 	
 	//Constructeurs
    Weapon(string nom, int degats); //Constructeur
    Weapon();
    
    //Affichage
    void display();
    
    //getteur
    int getValue();
    
    //redefinition de la méthode virtuelle
    bool isFood();
    
    
 
 
    protected:
 	
 	//Puissance de l'arme
    int degats;
    
};

#endif
