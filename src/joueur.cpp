#include "../include/Joueur.h"
#include "../include/Table.h"
#include "Paquet_cartes.cpp"
#include <iostream>

Joueur::Joueur(){}

Joueur::Joueur(string name,int Rg)
{
	Nom=name;
	Rang=Rg;
}

string Joueur:: getNom()const
{
    return Nom;
}


int Joueur:: getRang()const
{
    return Rang;
}
int& Joueur::setRang()
{
	return Rang;
}

Paquet_cartes Joueur:: get_player_paquet()const
{
	return Paquet;
}
Paquet_cartes& Joueur:: set_player_paquet()
{
	return Paquet;
}

void Joueur::operator=(Joueur cop)
{
    Nom = cop.getNom();
    Rang = cop.getRang();
    Paquet = cop.get_player_paquet();}
// int main(){
// 	Joueur J("Aziz",1);
// 	Joueur J1("Khalil",2);
// 	Joueur J2("Mohamed",3);
// 	cout<<"Testing Joueur.cpp"<<endl;
// 	cout<<"Nom des joueurs : "<<J.getNom()<<" "<<J1.getNom()<<" "<<J2.getNom()<<endl;
// 	J2=J1;
// 	cout<<"Changement en cours"<<endl;
// 	cout<<"Nom des joueurs : "<<J.getNom()<<" "<<J1.getNom()<<" "<<J2.getNom()<<endl;}

// vector<Carte> Joueur::cartes_possible(Table& T,string atout)
// {	
// 	vector<Carte> cartes;
// 	//Carte plus_grande_carte =T.compareTableCards(atout); //la plus grande carte sur table
	
// }


// void Joueur::sortir_carte(Table& T,Carte carte_choisi)
// {
// 	T.getCardsOnTable().push_back(carte_choisi);
// }
