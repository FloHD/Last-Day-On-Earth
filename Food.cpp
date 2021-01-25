#include"Food.h"
#include<string>

using namespace std;


//Constructeurs
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------

Food::Food(string nom) : Item(nom)
{
	srand (time(NULL));
	//On genere un nomber aléatoire entre 3 et 7 afin de déterminer la valeur de l'attribut nbreClaory
	int nbrAlea=rand()%5+3;
	this->nbreCalory=nbrAlea;
}
Food::Food(string nom,int nbreCalory): Item(nom),nbreCalory(nbreCalory){	
}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------


//getteur
int Food::getValue(){
	return nbreCalory;
}

//affichage stat de foos
void Food:: display(){
	cout<<"Nom de  : "<<nom<<endl;
	cout<<"Energie calorifique: "<<this->nbreCalory<<endl;
	
}

bool Food::isFood(){
	return true;
}
