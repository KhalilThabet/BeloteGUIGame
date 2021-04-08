#include "Joueur.h"
#include <iostream>
#include "Paquet_cartes.h"

Joueur::Joueur(){}

Joueur::Joueur(string name,int c)
{
	Nom=name;
	Rang=c;
}

string Joueur:: getNom()
{
    return Nom;
}


int& Joueur:: getRang()
{
    return Rang;
}

Paquet_cartes& Joueur:: get_player_paquet()
{
	return Paquet;
}



/*bool Joueur:: Couleur_exist_EnMain(Couleur couleur){}

virtual Carte sortir_Carte(Carte carte_avant, Couleur atout){}

vector<Carte> Joueur:: cartes_possible(Carte carte_avant,Couleur atout){}*/
