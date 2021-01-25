#include"Quete.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Quete::Quete(string nom): nom_quete(nom), fini(false)
{ 
}

//getteur
bool Quete::isFinish(){
	return this->fini;
}

//getteur
string Quete::getNom(){
	return this->nom_quete;
}


	




