#ifndef QUETE_H
#define QUETE_H

#include <string>
using namespace std;
//classe mere de Chasse et Collecte
class Quete
{
    public:
 	
 	//Constructeur avec comme parametre le nom de la quete
    Quete(string nom); 
    
    // fonction virtuelle pure qui permet de verifier si les conditions de quete ont été respecté
    virtual void VerifQueteAccompli()=0;
    
    // renvoie si la qiete est fini
    bool isFinish();
    
    // fonction virtuelle pure permettant l'affichage des données de la quete
    virtual void display()=0;
    
    //Revnoit de l'attribut nom
    string getNom();
    
    //Méthode virtuelle pure permeettant de modifier la valeur e l'attribut
    virtual void setValue(int i)=0;
    
 
 
    protected:
 
 	//false si quete non fini, true pour quete fini
    bool fini;
    //nom de la quete
    string nom_quete;
};

#endif
