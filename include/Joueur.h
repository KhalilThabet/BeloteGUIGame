#ifndef JOUEUR_H_
#define JOUEUR_H_
#include <vector>
#include "Paquet_cartes.h"
#include <string>


using namespace std ;
class Joueur
{
private:

	int Rang; 					//Rang du joueur durant jeu
	string Nom;					//Definie le nom du Joueur 
	Paquet_cartes Paquet;       //Objet Paquet de cartes chez un joueur
	
    

public:

	Joueur();
	Joueur(string,int);                //constructeur avec parametres
	int getRang()const;			           //Accesseur de l'attribut Rang
	int& setRang();
	string getNom()const; 				   //Accesseur de l'attribut Nom

	Paquet_cartes get_player_paquet()const;  //Acceseur
	Paquet_cartes& set_player_paquet(); //Mutateur
	
	void operator=(Joueur); //surcharge de l'operateur d'affectation

	// vector<Carte> cartes_possible(Table&,string);// retourne un vecteur contenant tout les cartes possible à sortir
	// virtual Carte choisir_carte()=0; // /retourne carte aprés selection et le supprime du paquet
	// void sortir_carte(Table&,Carte);//affecte la carte choisis vers table_cards
};



#endif // JOUEUR_H