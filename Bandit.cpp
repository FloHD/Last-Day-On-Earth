#include "Bandit.h"


//Constructeur
Bandit::Bandit(string nom): Ennemi(nom,8),w() {	
}


void Bandit:: attaquer(PersonnageActif & p){
	srand (time(NULL));
	
	//On génère un nombre aléatoire entre 1 et 10
	int nbrAlea=rand()%10+1;
	
	//en focntion du taux d'échec, l'attaque peut réussir ou non
	if(nbrAlea<=this->tauxEchec){
		
		//modification de la vie de l'opposant en focntion de l'attaque de base du bandit + la puissance de son arme
		p.setLife(-(this->getAttaque()+this->w.getValue()));
	}
	
	//cas où il y au un echec
	else{
		
		//affichage permettant d'indiqué que le bandit a raté son coup
		cout<<"Le bandit a rate son attaque"<<endl<<endl;
	}
}


void Bandit::display(){
	
	//affichage sur plusieurs lignes
	cout<<"Nom :"<<this->nom<<endl;
 	cout<<"Force d'attaque' :"<<this->attaque<<endl;
 	cout<<"Nom de l'arme :"<<this->w.getNom()<<endl;
 	cout<<"Puissance de l'arme :"<<this->w.getValue()<<endl;
 	cout<<"Vie :"<<this->life<<endl;
}


Item & Bandit::recompense(){
	//on retourne l'attribut arme du bandit
	return this->w;
	}
	
	
