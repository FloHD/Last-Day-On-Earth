#ifndef COLLECTE_H
#define COLLECTE_H

#include"Quete.h"


//Classe fille de Quete
class Collecte : public Quete

{
 public:
 	
 	//Constructeur avec comme parametre le nombre de calory
    Collecte(int nombreCalory); 
    
    // redefinition de la méthode
    void VerifQueteAccompli();
    
    // modifica&teur de l'attribut nombre calory
    void setValue(int nbreCal);
    
    //affichage des paramètres de la quete
    void display();
    
 
 
    protected:
 	//quantité de à collecter
    int nombreCalory;
    
};

#endif
