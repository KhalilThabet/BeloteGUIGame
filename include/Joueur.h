#ifndef JOUEUR_H_
#define JOUEUR_H_
#include "Paquet_cartes.h"

using namespace std ;
class Joueur
{
private:

	int Rang; 												//Rang du joueur durant jeu
	string Nom;												//Definie le nom du Joueur 
	vector<Carte> Paquet;       							//Objet Paquet de cartes chez un joueur
	
    

public:

	Joueur();
	Joueur(string,int);               			 			//constructeur avec parametres
	int& getRang();			           						//Accesseur de l'attribut Rang
	void setRang(int& a);									//Mutateur de l'attribut Rang
	string& getNom(); 				  		 				//Accesseur de l'attribut Nom

	vector<Carte>& get_player_paquet(); 				 	//Acceseur de l'attribut Paquet
	void set_player_paquet(vector<Carte>& P); 				//Mutateur de l'attribut Paquet
	
	void operator=(Joueur); 								//surcharge de l'operateur d'affectation

	vector<Carte> cartes_possible(vector<Carte>,string);	// retourne un vecteur contenant tout les cartes possible à sortir
	Carte choisir_carte(vector<Carte>&); 					//retourne carte aprés selection et le supprime du paquet
	void sortir_carte(vector<Carte>&,Carte);				//affecte la carte choisis vers table_cards
};



#endif // JOUEUR_H