#include "Table.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>
Table::Table(vector<Joueur> Players_list,Equipe team1,Equipe team2)
{	
	Equipe T1=team1;
	Equipe T2=team2;
	Joueurs = Players_list;
	
	ifstream sortie("../Belote.txt");		//Base de donne contenant les cartes du jeu
	if (sortie)
	{
		for (int i = 0;i < 32;i++)
		{
			Carte temp;					//Creation d'un objet temporaire Carte 
										//pour stocker les informations sortante
										//de la base de donnee
										
			sortie >> temp.getCouleur();
			sortie >> temp.getValeur();
			sortie >> temp.getVal_atout();
			sortie >> temp.getVal_hors_atout();
			AllCards.push_back(temp);
		}
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier en lecture" << '\n';
	}
}


vector<Carte>& Table::getAllCards() {		//Accesseur Attribut AllCards
	return AllCards;
}
vector<Joueur>& Table::getJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}


Equipe Table::getT1()						//Accesseur Attribut T1
{
	return T1;
}


Equipe Table::getT2()						//Accesseur Attribut T2
{
	return T2;
}

void Table::melange()						//Melange des cartes du vecteur AllCards
{
	int b;
	for (int a = 0;a < 32;a++)
	{
		Carte C;
		b = rand() % 32;
		C = AllCards[a];
		AllCards[a] = AllCards[b];
		AllCards[b] = C;
	}

}

