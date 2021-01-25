#include"Base.h"
#include <string>
#include <iostream>

using namespace std;


//CONSTRUCTEUR
Base::Base() : select(0), player("Ken Le Suvivant",2,1,2,30), nonPlayer("Ennemi")
{
}

//GESTION DEPLACEMENT
void Base::deplacer(char &c){
		
		cout<<endl;
		
		//cas pour la map de la base
		if(select==0){
			
			//Vérification si il il n y a pas un mur sur la case où le joueur veut aller et Eviter de sortir du tableau 
			if(c=='z' && player.getPos_x()>1 && terrain[player.getPos_x()-1][player.getPos_y()]!=1 && terrain[player.getPos_x()-1][player.getPos_y()]!=4) player.setPos_x(player.getPos_x()-1);
				else if(c=='s' && player.getPos_x()<10 && terrain[player.getPos_x()+1][player.getPos_y()]!=1 && terrain[player.getPos_x()+1][player.getPos_y()]!=4) player.setPos_x(player.getPos_x()+1);
				else if(c=='q' && player.getPos_y()>1 && terrain[player.getPos_x()][player.getPos_y()-1]!=1 && terrain[player.getPos_x()][player.getPos_y()-1]!=4) player.setPos_y(player.getPos_y()-1);
				else if(c=='d' && player.getPos_y()<10 && terrain[player.getPos_x()][player.getPos_y()+1]!=1 && terrain[player.getPos_x()][player.getPos_y()+1]!=4) player.setPos_y(player.getPos_y()+1);
				
				
				//si le joueur se retrouve sur une case porte
				if(terrain[player.getPos_x()][player.getPos_y()]==6){
					//on passe sur la map du wasteland
					select=1;
					player.setPos_x(13);
					player.setPos_y(15);
				}
		}
		//cas pour la map d uwasteland
		else{
			
			//Vérification si il il n y a pas un mur sur la case où le joueur veut aller et Eviter de sortir du tableau
			if(c=='z' && player.getPos_x()>1 && wasteland[player.getPos_x()-1][player.getPos_y()]!=1 && wasteland[player.getPos_x()-1][player.getPos_y()]!=4) player.setPos_x(player.getPos_x()-1);
				else if(c=='s' && player.getPos_x()<18 && wasteland[player.getPos_x()+1][player.getPos_y()]!=1 && wasteland[player.getPos_x()+1][player.getPos_y()]!=4) player.setPos_x(player.getPos_x()+1);
				else if(c=='q' && player.getPos_y()>1 && wasteland[player.getPos_x()][player.getPos_y()-1]!=1 && wasteland[player.getPos_x()][player.getPos_y()-1]!=4) player.setPos_y(player.getPos_y()-1);
				else if(c=='d' && player.getPos_y()<18 && wasteland[player.getPos_x()][player.getPos_y()+1]!=1 && wasteland[player.getPos_x()][player.getPos_y()+1]!=4) player.setPos_y(player.getPos_y()+1);
					
			
		
			//si le joueur se retrouve sur une case porte
			if(wasteland[player.getPos_x()][player.getPos_y()]==6){
				//on passe sur la map de la base
				select=0;
				player.setPos_x(3);
				player.setPos_y(1);
			}
		}
	}

	//affichage
	void Base::display(){ 
		
		//fonction d'affichage de la base;
		int i,j=0;
		
		//cas de la base
		if(select==0){
		
		//double for pour parcourir le talbeua 2D et afficher en fonction de la valeur contenu dans la case
		for(i=0;i<12;i++){	
				cout<<"#  ";
			for(j=0;j<12;j++){
				if(i==player.getPos_x() && j==player.getPos_y()) cout<<"J  ";
				else if(terrain[i][j]==0) cout<<".  ";
				else if(terrain[i][j]==1) cout<<"=  ";
				else if(terrain[i][j]==3) cout<<"P  ";
				else if(terrain[i][j]==4) cout<<"   ";
				else if(terrain[i][j]==5) cout<<"+  ";
				else if(terrain[i][j]==6) cout<<"D  ";
				else if(terrain[i][j]==7) cout<<"H  ";
				else if(terrain[i][j]==8 && j>0) cout<<"#  ";
				else if(terrain[i][j]==11) cout<<"F  ";
			}
			cout<<endl;
		}
		//cas du wasteland / select=1
		}else{
			//double for pour parcourir le talbeua 2D et afficher en fonction de la valeur contenu dans la case
			for(i=0;i<20;i++){
				cout<<"#  ";
			for(j=0;j<20;j++){
				if(i==player.getPos_x() && j==player.getPos_y()) cout<<"J  ";
				else if(wasteland[i][j]==0) cout<<".  ";
				else if(wasteland[i][j]==1) cout<<"=  ";
				else if(wasteland[i][j]==3) cout<<"P  ";
				else if(wasteland[i][j]==4) cout<<"   ";
				else if(wasteland[i][j]==5) cout<<"+  ";
				else if(wasteland[i][j]==6) cout<<"D  ";
				else if(wasteland[i][j]==7) cout<<"H  ";
				else if(wasteland[i][j]==8 && j>0) cout<<"#  ";
				else if(wasteland[i][j]==9) cout<<"M  ";
				else if(wasteland[i][j]==10) cout<<"B  ";			
			}
			cout<<endl;
		}	
		}
	}
	
	void Base::effetWasteland(){
		
		//cas si le joueur manque d'eau ou de nourriture
		if(player.getFood()==0 && player.getWater()==0) player.setLife(-2);
		else if(player.getFood()==0 || player.getWater()==0) player.setLife(-1);
		
		
		// a chaque mouvement, il perdra 1 en eau et en nourriture
		player.setFood(-1);
		player.setWater(-1);
	}
	void Base::showTouche(){
		
		cout<<"------------------"<<endl;
 		cout<< "Description des touches"<< endl<<"| "<<endl;
 		cout<<"z : se deplacer vers le haut"<<endl;
 		cout<<"s : se deplacer vers le bas"<<endl;
 		cout<<"q : se deplacer vers la gauche"<<endl;
 		cout<<"d : se deplacer vers la droite"<<endl;
 		cout<<"m : acces au menu"<<endl;
 		cout<<"z et s : déplacement dans le menu"<<endl;
 		cout<<"m : acces au menu"<<endl;
 		cout<<"w : valider la selection de la section voulu"<<endl;
 		cout<<"e : retourner en arière dans le menu ou sortir du menu"<<endl;
 		cout<<""<<endl;
 		cout<<"------------------"<<endl;
		
	}
	int Base::gestionMenus(char c){
		system("cls");
		if (c=='t')nonPlayer.getQuete()[player.getQuete()]->display();//on montre la quete acitve
		else if (c=='a')player.showState();//on montre l'atat du joueur
		else if (c=='z')player.showWeapons();//on montre les armes du joueurs
		else if (c=='y')player.showActivateWeapon();// On montre l'arme active
		else if (c=='u'){//changement d'arme active
			int c1;
			cout<<endl<<"Rentrer l'indice de l'arme voulue"<<endl;
			cin>>c1;
			player.changeWeapon(c1);
			cout<<"l'arme selectionne est :"<<endl;
			player.showActivateWeapon();	
		}else if (c=='o'){//manger de la nourritue
			int c1;
			player.showFoods();
			cout<<endl<<"Rentrer l'indice de la nourriture voulue"<<endl;
			cin>>c1;
			
			//verif si le caractere rentré est un nombre
			
			//nourrissage du joueur
			player.feed(c1);
			
		}
		cout<<endl<<endl<<"Appueyer sur e pour quitter le menu + Entree"<<endl;
		
	}
	
	void Base::showCommande(){
		cout<<endl<<"Entrer une diretion pour vous deplacer(q,z,s,d) +Entree"<<endl;
		cout<<"Appuyer sur la touche m afin d'acceder au menu+ Entree"<<endl;
	}
	
	int Base::afficheMenu(){
		system("cls");
		cout<<"a=Stat player"<<endl;
		cout<<"z=Liste Armes"<<endl;
		cout<<"r=Quitter"<<endl;
		cout<<"t=Quete active"<<endl;
		cout<<"y=Arme active"<<endl;
		cout<<"u=Changer arme active"<<endl;
		cout<<"o=se nourir"<<endl;
		
		cout<<endl<<endl<<"Appuyer sur (a,z,r,t,y,u ou o) pour acceder aux différents sous menus + Entree"<<endl;
		cout<<"Appuyer sur e pour quitter le menu + Entree"<<endl;
		
		char c;
		cin>>c;
		
		if(c=='r') return 1;
		else if (c=='e'){
			system("cls");
			return 0;
		}else{
			this->gestionMenus(c);
		}
		this->sortirMenu(1);
		return 0;
		
	}
	void Base::verifLieuBase(){
		system("cls");
		int compt=0;
		
		//case Pnj
		if(this->select==0 && terrain[player.getPos_x()][player.getPos_y()]==3) {
		nonPlayer.afficheQuetes();
		this->setQueteJoueur();
		compt=1;
		
		//case feeder 
		}else if(this->select==0 && terrain[player.getPos_x()][player.getPos_y()]==11) {
		player.feeder();
		compt=0;
		
		//case de l'eau
		}else if(terrain[player.getPos_x()][player.getPos_y()]==5) {
		player.drink();
		compt=0;
		}
		
		//case Hopital
		else if(this->select==0 && terrain[player.getPos_x()][player.getPos_y()]==7) {
		player.heal();
		compt=0;
		}
		else{
			return;
	 }
		
		
		//sortie du menu
		this->sortirMenu(compt);
		return;
		
		}
		
		
		
		void Base::verifLieuWasteland(){
			system("cls");
		int compt=0;
		int combat=0;
		int win=1;
		
			//case eau
			if(wasteland[player.getPos_x()][player.getPos_y()]==5) {
			player.drink();
			compt=0;
		}
		//case Monstre
		if(wasteland[player.getPos_x()][player.getPos_y()]==9){
			Monstre m=Monstre("Monster");
			PersonnageActif & p=m;
			win=player.combattre(p);
			if(win==0){
				player.victoireCombat(m,nonPlayer);
				player.majQueteChasse(1,nonPlayer);
					
			}
			} 
			
		//case Bandit
		else if(wasteland[player.getPos_x()][player.getPos_y()]==10){
			
			Bandit m=Bandit("Mavic");
			PersonnageActif & p=m;
			win=player.combattre(p);
			if(win==0){
				player.victoireCombat(m,nonPlayer);
				player.majQueteChasse(1,nonPlayer);
					
			}
			} 
			
		if(win==0){
			wasteland[player.getPos_x()][player.getPos_y()]=0;// on change la valeur de la case car l'ennemi est mort
		}
		
		//sortie du menu
		this->sortirMenu(compt);
		return;
		}
		
		void Base::viderAllocution(){
			player.viderAllocution();
			nonPlayer.viderAllocution();
		}
		
		void Base::sortirMenu(int compt){
			char c;
		while(compt==1){
		cin>>c;
		if(c=='e') {
			system("cls");
			return;
		}	
		}
		system("cls");
			return;
		}
	
	

	//méthode principal faisant tourner le jeu
	void Base::Jeu(){
		char c;
		
		//affihce le terrrain
		this->player.showState();
		this->display();
		this->showCommande();
		
		//blockeur pour lire l'aide au jeu
		int mur=0; // empecher l'affichage du terrain
		
		//boucle de combat en tant que tel
		while(1){
			//verif si les quetes sont finis
			if(nonPlayer.QuetesFini()==true){
			system("cls");
			cout<<endl<<endl<<"Vous avez fait toutes les quetes, Bravo !!";	
			return;
			}
			
				
			//rentrer une lettre (direction, menu,...)
			cin>>c;
			
			//clear du terminal
			system("cls");
			
			//dans le cas où la touche tapée vaut une des 4 directions
			if(c=='z' || c=='s' || c=='q' || c=='d') {
				
				//Appel à la fonction pour déplacer le joueur
				this->deplacer(c);
				
				//cas où le joueur est dans le wasteland
				if(select==1)this->effetWasteland();
				
			//si c != touche direction et c==h
			//On affiche l'aide au joueur	
			}else if(c=='h'){
				
				//tant qu'on a pas appuyé sur e, on reste dans ce menu d'aide
				while(mur==0){
					system("cls");
					
					//affichage de l'aide
					this->showTouche();
					cin>>c;
					if(c=='e') mur=1;	
				}
				mur=0;	
			}
			
			//si c != touche direction et c==m
			//On affiche le menu du joueur
			else if(c=='m'){
				
				//Appel à la fonction d'affichage
				int rep=this->afficheMenu();
				
				//Cas où le joueur a appuyé sur la touche pour quitter le jeu
				if(rep==1){
					this->viderAllocution();
					return;
				}	
			}
			
			//verification des cases pour voir si le joueur n'est pas sur une case liée à une action
			if(select==0)verifLieuBase();
			else if(select==1)verifLieuWasteland();
			
			//Verifie si le joueur est mort
			if(player.getMort()==1 || player.getLife()==0){
				system("cls");
				cout<<"vous avez perdu"<<endl;
				
				this->viderAllocution();
				
				//On quitte le jeu
				return;
				
			}
			
			//à la fin de la boucle on réaffiche le terrain avec les mises à jours si il y en a eu
			this->player.showState();
			this->display();
			this->showCommande();
			
		}
	}
	//mofification de la quete active
	void Base::setQueteJoueur(){
		
		int i;
		
		
		cout<<"Veuillez rentrer l'indiec de la quete vouslue( commence à 0)"<<endl;
		//on rentre un index du tableau de quetes du pnj
		cin>>i;
		//on verfire si la quete n'est pas déjà faite
		if(nonPlayer.isDisponible(i)==true){
			cout<<"changement de quete active effecutée"<<endl;
			cout<<endl<<endl<<"Appueyer sur e pour quitter le menu + Entree"<<endl;
			player.setQuete(i);
		}
		
		
		
		
		
		
		
		
	}
