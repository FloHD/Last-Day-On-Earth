#include <string>
#include "Pnj.h"
#include"Joueur.h"
#include "Quete.h"
#include "Collecte.h"
#include "Monstre.h"
#include <cstdlib>

using namespace std;
class Base

{
 public:
 
    Base(); //Constructeur
    
    //déplacer le joueur sur la mpa
    void deplacer(char &c);
    
    //Boucle jeu 
    void Jeu();
    
    //en focntion des tocuhes, on entrera  dans un des sous menus
    int gestionMenus(char c);
    
    //check pour voir si lorsque  le joueur est dans la base, il n'est pas sur une case avec un effet
    void verifLieuBase();
    
    //check pour voir si lorsque  le joueur est dans le wasteland, il n'est pas sur une case avec un effet
    void verifLieuWasteland();
    
    //impact sur les attributs du joueur lié à la chaleur uniquement dans la map Wasteland
    void effetWasteland();
    
    //fonction permettant de sortir des menus
    void sortirMenu(int compt);
    
    //Méthode pour désallouer la mémoire
    void viderAllocution();
 	
 	//Méthode perméttant de modifier la quete choisi par le joueur
 	void setQueteJoueur();
 	
 	//Méthode Affichage-----------------------------------------
 	
 	//aide pour le joueur
    void showCommande();
    
    //affiche menu
    int afficheMenu();
    
    //l'aide des touches
    void showTouche();
    
    //Affiche le terrain
    void display();
    
    //---------------------------------------------------------
 	
 
    private:
	
	//Pnj qui donne les quetes
	Pnj nonPlayer;
	
	//Joueur se dépalcant et combattant sur la map
  Joueur player;
  
  
  int select;// 0 quand joeur dans base et 1 quand joueur dans wasteland
  
  
  //tableau representant la base
  int terrain[12][12]={
			{8 , 8 , 8 ,8, 8 , 8, 8, 8, 8, 8, 8 , 8},
  			{8 ,0, 0, 0, 0 ,5 , 4 ,4 ,4 ,5 , 0, 8} ,   
   			{8 ,0, 0, 0, 0 ,0 , 5 ,5 ,5 ,0 , 0, 8} ,
   			{8 ,6, 0, 0, 0 ,0 , 0 ,0 ,0 ,0 , 11, 8} ,
   			{8 ,0, 0, 0, 0 ,0 , 0 ,0 ,0 ,0 , 11, 8} ,
   			{8 ,0, 0, 0, 0 ,0 , 0 ,0 ,0 ,0 , 0, 8} ,
   			{8 ,1, 1, 1, 0 ,0 , 1 ,1 ,0 ,1 , 1, 8} ,
   			{8 ,0, 0, 0, 0 ,0 , 1 ,0 ,0 ,0 , 0, 8} ,
   			{8 ,0, 0, 0, 0 ,0 , 1 ,0 ,0 ,0 , 0, 8} ,
   			{8 ,0, 7, 7, 0 ,0 , 1 ,0 ,3 ,0 , 0, 8} ,
   			{8 ,0, 7, 7, 0 ,0 , 1 ,0 ,0 ,0 , 0, 8},
   			{8 , 8 , 8 , 8 ,8, 8, 8, 8, 8, 8, 8 , 8},
		};
		
	 //tableau representant le wasteland
	int wasteland[20][20]={// 9 pour les mosntres 10 pour bandits
			{8 , 8, 8 ,8, 8 ,8 ,8 , 8, 8, 8, 8 , 8, 8, 8, 8, 8, 8, 8, 8, 8},
  			{8 , 4, 4, 5, 0 ,9 ,0 ,1 ,0 ,0 , 1, 0, 0, 0, 0, 1, 1, 1, 1 ,8} ,   
   			{8 , 4, 4, 5, 0 ,0 ,0 ,1 ,9 ,9 , 1, 0, 0, 0, 0, 1, 0, 0, 1, 8} ,
   			{8 , 5, 5, 0, 0 ,0 ,0 ,1 ,0 ,0 , 1, 0, 0, 0, 0, 1, 0, 0, 1, 8} ,
   			{8 , 0, 10, 0, 0 ,0 ,9 ,1 ,0 ,1 , 1, 0, 0, 0, 0, 1, 1, 0, 1, 8} ,
   			{8 , 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 , 0, 0, 0, 0, 0, 0, 0, 0 ,0, 8} ,
   			{8 , 1, 1, 1, 1 ,0 ,0 ,0 ,0 ,0 , 10, 0, 0, 9, 0, 0, 0, 0, 0, 8} ,
   			{8 , 0, 0, 0, 1 ,0 ,0 ,4 ,4 ,4 , 4, 0, 0, 0, 10, 0, 0, 0 ,0, 8} ,
   			{8 , 0, 9, 0, 1 ,0 ,0 ,4 ,8 ,8 , 4, 9, 0, 0, 0, 0, 0, 9, 0, 8} ,
   			{8 , 0, 0, 0, 1 ,0 ,0 ,4 ,8 ,8 , 4, 0, 0, 0, 0, 0, 0, 0, 0, 8} ,
   			{8 , 0, 10, 0, 0 ,0 ,0 ,4 ,4 ,4 , 4, 0, 0, 0, 0, 0, 0, 0, 0, 8},
   			{8 , 0, 0, 0, 1 ,0 ,0 ,0 ,0 ,0 , 0, 0, 0, 9, 0, 0, 0, 0, 0, 8},
   			{8 , 9, 0, 0, 1 ,0 ,10 ,0 ,9 ,0 , 0, 0, 0, 0, 0, 0, 0, 0, 10, 8},
   			{8 , 1, 1, 1, 1 ,0 ,0 ,0 ,0 ,0 , 0, 0, 0, 1, 1, 6, 1, 1, 0, 8},
   			{8 , 0, 0, 0, 1 ,0 ,0 ,5 ,5 ,5 , 5, 0, 0, 1, 4, 4, 4, 1, 0, 8},
   			{8 , 10, 0, 0, 1 ,0 ,5 ,4 ,4 ,4 , 4, 5, 0, 1, 4, 4, 4, 1, 0, 8},
   			{8 , 0, 0, 10, 0 ,0 ,5 ,4 ,4 ,4 , 4, 5, 0, 1, 4, 4, 4, 1, 0, 8},
   			{8 , 0, 0, 10, 0 ,0 ,5 ,4 ,4 ,4 , 4, 5, 0, 1, 1, 1, 1, 1, 0, 8},
   			{8 , 0, 0, 0, 1 ,10 ,0 ,5 ,5 ,5 , 5, 0, 0, 0, 0, 0, 0, 0, 0, 8},
   			{8 , 8, 8, 8 ,8 ,8 , 8, 8, 8, 8, 8 , 8, 8, 8, 8, 8, 8, 8, 8, 8},
		};
  
    
    
};
