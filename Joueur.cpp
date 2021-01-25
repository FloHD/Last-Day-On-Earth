#include "Joueur.h"
#include <iostream>

using namespace std;


//Constructeur 
 Joueur::Joueur(string nom,int pos_x,int pos_y,int attaque ,int life): PersonnageActif(nom,life,attaque), pos_x(pos_x), pos_y(pos_y),food(40),water(40),indiceQuete(0)
{
	this->weapons.push_back(new Weapon("Poing Americain",3));
	this->armeActive=0;

 }

 
 //GUETTEURS
 //----------------------------------------------------------
 //----------------------------------------------------------
 
 int Joueur::getPos_x(){
 	return pos_x;
 }
 int Joueur::getPos_y(){
 	return pos_y;
 }
 int Joueur::getQuete(){
 	return this->indiceQuete;
 }
  int Joueur::getWater(){
 	return this->water;
 }
 int Joueur::getFood(){
 	return this->food;
 }
 int Joueur::getArmeActive(){
	return this->armeActive;
}

 //----------------------------------------------------------
 //----------------------------------------------------------
 
 
 //SETTEURS
//----------------------------------------------------------
//----------------------------------------------------------
 
 
 void Joueur::setPos_x(int nbre){
 	pos_x=nbre;
 }
 void Joueur::setPos_y(int nbre){
 	pos_y=nbre;
 }
 void Joueur::drink(){
 	this->water=40;
 }
  void Joueur::setQuete(int i){
 	this->indiceQuete=i;
 }
 
  void Joueur::setWater(int nbre){
 	water+=nbre;
 	if(water<0){
	 water=0;
	 
	}
 }
  void Joueur::setFood(int nbre){
 	food+=nbre;
 	if(food<0){
	 food=0;
	 
	}
 }
 void Joueur::feeder(){
	this->food=40;
}
void Joueur::heal(){
 	life=30;
 }
 
//----------------------------------------------------------
//----------------------------------------------------------



//SETTEURS COMPLEXES
//----------------------------------------------------------
//----------------------------------------------------------
 
  void Joueur::feed(int nbre){
 		
 		if(nbre>=0 && nbre<foods.size()){
		 
 		this->food+=foods[nbre]->getValue();
 		if(this->food>40){
 			food=40;
		 }
		 
		 cout<<"J'ai bien mangé !!"<<endl;
		 this->foods.erase(foods.begin()+nbre);
	}
	else{
		cout<<"Aucune nourriture n'est lié à l'indice rentré"<<endl;
	}
 }

void Joueur::changeWeapon(int indice){
	
	//verifie si l'indice rentre est bien dans la liste des armes en terme d'index du vector
	if(indice>=0 && indice<this->weapons.size()){
		this->armeActive=indice;
	}
	
}
 	
//----------------------------------------------------------
//----------------------------------------------------------


//METHODE AFFICHAGE
//----------------------------------------------------------
//----------------------------------------------------------

//affichge
 void Joueur::showState(){
 	cout<<"------------------"<<endl;
 	cout<< "| "<<nom<< endl<<"| "<<endl;
 	cout<<"| life : "<<life<<endl;
 	cout<<"| food : "<<food<<endl;
 	cout<<"| water : "<<water<<endl;
 	cout<<"------------------"<<endl;
 }
 
 
  void Joueur::showActivateWeapon(){
 	weapons[this->armeActive]->display();
 }
 
 void Joueur::display(){
 	cout<<"Nom :"<<this->nom<<endl;
 	cout<<"Force d'attaque' :"<<this->attaque<<endl;
 	this->weapons[this->armeActive]->display();
 	cout<<"Vie :"<<this->life<<endl;
 	
 }
 
  void Joueur::showWeapons(){
 	int i=0;
 	for(i=0;i<this->weapons.size();i++){
 		cout<<endl<<i<<"-";
 		weapons[i]->display();
	 }
 }
 
 void Joueur::showFoods(){
 	int i=0;
 	
 	cout<<"Voici la nourriture que vous avez :"<<endl<<endl;
 	for(i=0;i<this->foods.size();i++){
 		cout<<endl<<i<<"-";
 		foods[0]->display();
	 }
 }

//----------------------------------------------------------
//----------------------------------------------------------

 
//Méthode pour les combats
//----------------------------------------------------------
//----------------------------------------------------------

 int Joueur::combattre(PersonnageActif & p1){
 				
 			//Affiche les 2 Personnages qui s'affrontent 
			 p1.display();
			 cout<<endl<<"VS"<<endl<<endl;
			 this->display();
			
			cout<<endl;
			 
			//Boucle de combat : tant que le combat n'est pas fini on reste dans la boucle 
			while(1){
				
				//Attaque du joueur 
				this->attaquer(p1);
				if(p1.getLife()<=0){
					p1.setMort(1);
					system("cls");
					return 0;// défaite ennemi
				}
				//Attaque de l'ennemi (Bandit/Monstre)
				p1.attaquer(*this);
				if(this->getLife()<=0){
					this->setMort(1);
					system("cls");
					return 1;//defaite joueur
				}
				
			}
 }
 
 
 
 void Joueur:: attaquer(PersonnageActif & p){
 	this->display();
 	p.display();
 	
 	
 	cout<<endl<<"----------------------------"<<endl;
 	cout<< "Choissisez votre action"<<endl;
 	cout<< "0- Attaquer avec votre arme"<<endl<<endl;
 	int var=1;
 	PersonnageActif & pl=*this;
 	if(p>pl) var=2;//si joueur moins fort, il a un boost d'attaque
 	
 	char c;
 	cin>>c;
 	cout<<endl;
 	
 	//modification de la santé de l'énnemu
 	if (c=='0')p.setLife(-(var*this->getAttaque()+weapons[this->armeActive]->getValue()));
 	
 	
 }
 
 
 
 void Joueur::victoireCombat(Ennemi & e,Pnj  & j){
 	srand (time(NULL));
 	//on genere un numero entre 1 et 10 afin de voir si on  recupere l'item de l'ennemi vaincu
	int alea=rand()%10+1 ;
	if(alea>4){
		
		//cas pour la food
		if(e.recompense().isFood()==true){
			this->foods.push_back(new Food(e.recompense().getNom(),e.recompense().getValue()));
			this->majQueteCollecte(e.recompense().getValue(),j);
		
		}
		//cas pour le water
		else{
			//inclusion dans le vector de weapons
			this->weapons.push_back(new Weapon(e.recompense().getNom(),e.recompense().getValue()));
		}
	}
 }

//----------------------------------------------------------
//----------------------------------------------------------


//Méthodes de Mise à jour des quetes
//----------------------------------------------------------
//----------------------------------------------------------
 void Joueur::majQueteChasse(int i,Pnj & j){
 	
 		//on verifie si la quete sélectione est une chasse au monstre
		if(j.getQuete()[this->getQuete()]->getNom()=="Chasse"){
			
			//on modifie la valeur de la variable de quete, dans ce cas ci le nombre d'ennemis à abattre est réduit de 1
			j.getQuete()[this->getQuete()]->setValue(i);
			
		//on verifiesi la quete est accomplie
		j.getQuete()[this->getQuete()]->VerifQueteAccompli();
		}
		
	}
		
	void Joueur::majQueteCollecte(int i,Pnj & j){
			
			//on verifie si la quete sélectione est une collecte 
			if(j.getQuete()[this->getQuete()]->getNom()=="CollecteFood"){
			
			//on modifie la valeur de la variable de quete, dans ce cas ci le nombre de calory à collecter est réduit de 1
			j.getQuete()[this->getQuete()]->setValue(i);
			
			//on verifiesi la quete est accomplie
			j.getQuete()[this->getQuete()]->VerifQueteAccompli();
			
	}
}



//----------------------------------------------------------
//----------------------------------------------------------


//Gestion mémoire
 void Joueur::viderAllocution(){
 	this->weapons.clear();
 	this->foods.clear();
 }

 

 
