#ifndef FOOD_H
#define FOOD_H

#include <string>
#include "Item.h"
#include <iostream>

using namespace std;

//classe Fille par rapoort à Item
class Food : public Item

{
 public:
 	
 	//Constructeurs
    Food(string nom);
    Food(string nom,int nbreCalory);
    
    //redefinition de méthode permettant de revonyer la valeur des calorys
    int getValue();
    
    //redef pour l'affichage des données
    void display();
    
    //redef pour renvyer si l'objet est un Food
    bool isFood();
    
    
 
 
    protected:
 
 	//nbre calory de l'aliment 
    int nbreCalory;
    
};


#endif
