#ifndef COLLECTE_H
#define COLLECTE_H

#include"Quete.h"


//Classe fille de Quete
class Collecte : public Quete

{
 public:
 	
 	//Constructeur avec comme parametre le nombre de calory
    Collecte(int nombreCalory); 
    
    // redefinition de la m�thode
    void VerifQueteAccompli();
    
    // modifica&teur de l'attribut nombre calory
    void setValue(int nbreCal);
    
    //affichage des param�tres de la quete
    void display();
    
 
 
    protected:
 	//quantit� de � collecter
    int nombreCalory;
    
};

#endif
