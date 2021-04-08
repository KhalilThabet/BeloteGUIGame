#include "Table.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>

Table::Table(vector<Joueur> Players_list,Equipe team1,Equipe team2)
{	
	T1=team1;
	T2=team2;
	Joueurs = Players_list;
	
	ifstream sortie("../Belote.txt");		//Base de donne contenant les cartes du jeu
	if (sortie)
	{
		for (int i = 0;i < 32;i++)
		{
			Carte temp;					//Creation d'un objet temporaire Carte 
										//pour stocker les informations sortante
										//de la base de donnee
										
			sortie >> temp.couleur;
			sortie >> temp.valeur;
			sortie >> temp.val_atout;
			sortie >> temp.val_hors_atout;
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
vector<Carte>& Table::getJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}

void Table::setAllPacket(i) {
	all_carte.erase(0)
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
		carte C;
		b = rand() % 32;
		C = all_carte[a];
		all_carte[a] = all_carte[b];
		all_carte[b] = C;
	}

}

