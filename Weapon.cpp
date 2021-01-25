#include"Weapon.h"


using namespace std;

//Constructeur
//-------------------------------------------------------------------
//-------------------------------------------------------------------
Weapon::Weapon(string nom,int degats) : Item(nom), degats(degats)
{
	
}
Weapon::Weapon(): Item("ArmeMelee"){
	srand (time(NULL));
	//gnere un nombre aleaoire ente 1 et 7 permettant de definir la puissance de l'arme
	int nbrAlea=rand()%7+1;

	degats=nbrAlea;
		
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------


//getteur
int Weapon::getValue(){
	return degats;
}

//affichage

void Weapon:: display(){
	//affiche sur plusieurs ligens
	cout<<"Nom de l'arme : "<<nom<<endl;
	cout<<"Puissance d'attaque: "<<this->degats<<endl;
}

bool Weapon::isFood(){
	return false;
}
