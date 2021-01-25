#ifndef PNJ_H
#define PNJ_H
#include <string>
#include "Quete.h"
#include "Chasse.h"
#include "Collecte.h"
#include "Personnage.h"
#include<vector>

using namespace std;
class Pnj:public Personnage

{
 public:
 
    Pnj(string nom); //Constructeur
    void afficheQuetes();
    int getNbreQuete();
    void setNbreQuete(int nbre);
    //Quete &  getQuete(int indice);
    void viderAllocution();
    vector<Quete*> getQuete();
    bool isDisponible(int indice);
    bool QuetesFini();
    
    
    
 
 
    protected:
 
   vector<Quete*> quetes;// nom du personnage
   int quetesRestantes; // nombre de quete restantes
    
};

#endif
