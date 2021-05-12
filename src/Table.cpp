#include "../include/Table.h"
#include <fstream>
Table::Table(vector<Joueur> Players_list,Equipe team1,Equipe team2)
{	
	Equipe T1=team1;
	Equipe T2=team2;
	Joueurs = Players_list;
	
	ifstream sortie("Belote.txt");		//Base de donne contenant les cartes du jeu
	if (sortie)
	{
		for (int i = 0;i < 32;i++)
		{
			Carte temp;					//Creation d'un objet temporaire Carte 
										//pour stocker les informations sortante
										//de la base de donnee
										
			sortie >> temp.setCouleur();
			sortie >> temp.setValeur();
			sortie >> temp.setVal_atout();
			sortie >> temp.setVal_hors_atout();
			AllCards.push_back(temp);
		}
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier en lecture" << '\n';
	}
}


vector<Carte> Table::getAllCards() {		//Accesseur Attribut AllCards
	return AllCards;
}
vector<Carte>& Table::setAllCards() {		//Accesseur Attribut AllCards
	return AllCards;
}
vector<Joueur>  Table::getJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}
vector<Joueur>&  Table::setJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}


Equipe Table::getT1()						//Accesseur Attribut T1
{
	return T1;
}
Equipe& Table::setT1()
{
	return T1;
}


Equipe Table::getT2()						//Accesseur Attribut T2
{
	return T2;
}
Equipe& Table::setT2()						//Accesseur Attribut T2
{
	return T2;
}

void Table::melange()						//Melange des cartes du vecteur AllCards
{
	cout<<"Entering Melange"<<endl;
	int b;
	for (int a = 0;a < 32;a++)
	{
		b = rand() % 32;
		cout << " B : "<<b<<endl;
		Carte C = AllCards[a];
		cout<<C.getValeur()<<" "<<C.getCouleur()<<endl;
		AllCards[a] = AllCards[b];
		AllCards[b] = C;
	}
	cout<<"Exiting melange\n";

}
Carte Table::compareTableCards(string atout){
	Carte Highest_Card=CardsOnTable[0];
	for(int i=1;i<4;i++){
		if (CardsOnTable[i].compare(Highest_Card,atout)>0){
			Highest_Card=CardsOnTable[i];
		}
	}
	return Highest_Card;
}
vector<Carte> Table::getCardsOnTable(){
	return CardsOnTable;
}
vector<Carte>& Table::setCardsOnTable(){
	return CardsOnTable;
}
