#ifndef CHASSE_H
#define CHASSE_H

#include"Quete.h"


//Classe fille de Quete
class Chasse : public Quete

{
 public:
 	
 	//Constructeur
    Chasse(int en,int nbre); 
    
    // redefinition de la méthode
    void VerifQueteAccompli();
    
    // on modifie l'attrbut nombre ennemis
    void setValue(int nbrEn);
    
    // afichage des paramètres de la quete
    void display();
    
 
 
    protected:
 	
 	//quantité de à collecter
    int nombreEnnemis;
    
    //si 1 => bandit sinon 2 Monstre// 3 ^pour les 2 types
    int type;
    
};

#endif
