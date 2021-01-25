#include"Item.h"
#include <string>
#include <iostream>

using namespace std;

//Constructeur
Item::Item(string nom_item) : nom(nom_item)
{
}
string Item::getNom(){
	//on renvoie l'attribut nom
	return nom;
}
