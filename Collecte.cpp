#include"Collecte.h"
#include"Quete.h"
#include <string>
#include <iostream>

using namespace std;

//Constreucteur
Collecte::Collecte(int calory) : Quete("CollecteFood"), nombreCalory(calory)
{ 
}

void Collecte:: VerifQueteAccompli(){
	if(nombreCalory<=0){
		fini=true;// si la quete est fini on modifie le booléen fini à true
			
	}
	
}

//setteur
void Collecte::setValue(int nbreCal){
	nombreCalory= nombreCalory - nbreCal;
	if(nombreCalory<0){//on met à 0 si la quatité de nourriture est inféruieur à 0
			nombreCalory=0;
	}
}

//affichge
void Collecte::display(){
		
		string Etat_Quete="Non";
		
		if(fini==true){
			Etat_Quete="Oui";
		}
		
		//Organisation de l'afficahge des informations
		cout<<"nom de la quete :"<<nom_quete<<endl;
		cout<<"type de quete : Collecte de nourriture"<<endl;
		cout<<"nombre de calory a apporter : "<<nombreCalory<<endl;
		cout<<"Quete termine :"<<Etat_Quete<<endl;
	}
	

	
	

