#ifndef ITEM_H
#define ITEM_H

#include <string>
#include<time.h>
#include<stdlib.h>

using namespace std;
//Classe mere par rapport � Food et Weapon
class Item

{
 public:
 	
 	//Constructeur
    Item(string nom);
    
    //m�tohde virtuelle d'affichage des informations li�es aux diff�rents items
    virtual void display()=0;
    
    //m�thode virtuelle permettant de renvoyer la valeur associ� � l'items 
    virtual int getValue()=0;
    
    //m�thode virtuelle permettant de renvoyer si l'objet est une Food
    virtual bool isFood()=0;
    
    //M�thode permettant de de renvoyer le nom de l'item
    string getNom();
    
    
 
 
    protected:
 	
 	//Nom de l'item
    string nom;
    
};

#endif
