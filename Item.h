#ifndef ITEM_H
#define ITEM_H

#include <string>
#include<time.h>
#include<stdlib.h>

using namespace std;
//Classe mere par rapport à Food et Weapon
class Item

{
 public:
 	
 	//Constructeur
    Item(string nom);
    
    //métohde virtuelle d'affichage des informations liées aux différents items
    virtual void display()=0;
    
    //méthode virtuelle permettant de renvoyer la valeur associé à l'items 
    virtual int getValue()=0;
    
    //méthode virtuelle permettant de renvoyer si l'objet est une Food
    virtual bool isFood()=0;
    
    //Méthode permettant de de renvoyer le nom de l'item
    string getNom();
    
    
 
 
    protected:
 	
 	//Nom de l'item
    string nom;
    
};

#endif
