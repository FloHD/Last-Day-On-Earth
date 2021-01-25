#include"Chasse.h"
#include"Quete.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Chasse::Chasse(int en,int nbre) : Quete("Chasse"), type(en),nombreEnnemis(nbre)
{ 
	
}


void Chasse:: VerifQueteAccompli(){
		//si le nombre d'ennemis, vaut 0, la quete est accomplie
		if(nombreEnnemis<=0){
			fini=true;
			
		}
	
	}

//setteur
void Chasse::setValue(int nbreEn){
		nombreEnnemis= nombreEnnemis - nbreEn;
		if(nombreEnnemis<0){// si nobre<0, on met à 0
			nombreEnnemis=0;
		}
	}

//affichage
void Chasse::display(){
		
		//affichge sur plusieurs lignes
		string Etat_Quete="Non";
		string type_Quete=" Chasse aux Monstres";
		
		if(type==0){
			type_Quete="Chasse aux bandits";	
		}
		else if(type==2){
			type_Quete="Chasse aux Ennemis";
		}
		
		
		if(fini==true){
			Etat_Quete="Oui";
		}
		
		//Organisation de l'affichage
		cout<<"nom de la quete :"<<nom_quete<<endl;
		cout<<"type de quete : "<<type_Quete <<endl;
		cout<<"nombre de d'ennemis a tuer' : "<<nombreEnnemis<<endl;
		cout<<"Quete termine :"<<Etat_Quete<<endl;
	}
