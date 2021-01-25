#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "PersonnageActif.h"
#include "Quete.h"
#include "Food.h"
#include "Weapon.h"
#include "Bandit.h"
#include "Monstre.h"
#include"Pnj.h"
#include<Vector>


class Joueur :public PersonnageActif

{
 public:
 	
 	//Constructeur
    Joueur(string nom,int pos_x,int pos_y,int attaque,int life); //Constructeur
    
    
    //setteur pour les attributs
    void setWater(int nbre);
    void setFood(int nbre);
    void setPos_x(int nbre);
    void setPos_y(int nbre);
    void setQuete(int i);
    
    //getteurs pour les attributs
    int getPos_x();
    int getPos_y();
    int getQuete();
    int getWater();
    int getFood();
    int getArmeActive();
    
    //m�thode pour changer d'arme pour le joueur
    void changeWeapon(int indice);
    
    //mise max pour Food
    void feeder();
    
    //mise max pour Water
    void drink();
    
    //mise max pour sant�
    void heal();
    
    //utiliser un des elements de l'attribut foods pour regangner un peu de food
	void feed(int indice);
    
    
    //montrer �tat g�neral du joeur 
    void showState();
    
    //montrer l'ensemble des armes du joueur
    void showWeapons();
    
    //montrner la liste de nourriutre
    void showFoods();
    
    //montrer la quete active via l'attibut indicequete
    void showActivateWeapon();
    
   
   	//m�thode pour la gestion des combats
    int combattre(PersonnageActif & p);
    
    //affichge de l'ensemble des donnzes du joueur
    void display();
    
    //redefinition pour la gestion de l'attaque 
     void attaquer(PersonnageActif & p);
    
    
    //Gerer la recompense du combat contre MOnstre/bandit
    void victoireCombat(Ennemi & e,Pnj & j);
    
    //d�sallouage de la m�moire pour les attribut qui ont �t� d�clar� de facon dynamique
	void viderAllocution();
    
    
    //m�thode pour la mise � jour des quetes de chasse
    void majQueteChasse(int nbre,Pnj & j);
    
    //m�thode pour la maj des quetes de collecte
 	void majQueteCollecte(int nbre,Pnj & j);
 
 
    protected:
 
 	//niveau de nourriture
    int food;
    
    //niveau d'eau
    int water;
    
    //position en x et y du joueur
    int pos_x;
    int pos_y;
    
   // entier inidiquat la quete active
   int indiceQuete;
    
    //tableau de nourritue et armes
    vector<Item *> foods;
    vector<Item *> weapons;
    
    //indice de l'arme active
    int armeActive;
    
    
};

#endif
