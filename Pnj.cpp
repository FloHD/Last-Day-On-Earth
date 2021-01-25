    #include <iostream>
	#include "Pnj.h"  
    using namespace std;  
   

Pnj::Pnj(string nom_perso): Personnage(nom_perso)
{
	
	quetes.push_back(new Collecte(5));
	quetes.push_back(new Chasse(0,5));
	this->quetesRestantes=2;
}
void Pnj::afficheQuetes(){
	
	cout<<"Les Quetes :"<<endl<<endl;
	quetes[0]->display();
	cout<<endl;
	quetes[1]->display();
	cout<<endl;
	cout<<"il vous reste "<<this->quetesRestantes<<" a effectuer"<<endl;
	
}

bool Pnj::QuetesFini(){
	int i=0;
	int clone=0;
	for(i=0;i<quetes.size();i++){
		if(quetes[i]->isFinish()==false){
			clone=clone+1;
		}
	}
	this->quetesRestantes=clone;
	
	if(clone==0)return true;
	else{
		return false;
	}
}
int Pnj::getNbreQuete(){
	this->quetesRestantes;
}
void Pnj::setNbreQuete(int nbre){
	this->quetesRestantes=nbre;
}
void Pnj::viderAllocution(){
	this->quetes.clear();
}
vector<Quete*> Pnj::getQuete(){
	
	return quetes;	
}

bool Pnj::isDisponible(int indice){
	//vlaidation de l'indice rentree
	if(indice<this->quetes.size() && indice>=0){
		
		if(quetes[indice]->isFinish()==false){
			return  true;
			
		}
		//si quete fini, on informe sur le teminal
		else{
			cout<<"La quete sélectionné est déjà faite"<<endl;
			return false;
		}
	}
	//cas pour indice non valable
	cout<<"incide rentree non valable"<<endl;
	return false;
}
