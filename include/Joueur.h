#ifndef JOUEUR_H_
#define JOUEUR_H_
#include "Carte.h"
#include <vector>
#include "Paquet_cartes.h"
#include <string>

using namespace std ;
class Joueur
{
protected:

	int Rang; 					//Rang du joueur durant jeu
	string Nom;					//Definie le nom du Joueur 
	Paquet_cartes Paquet;       //Objet Paquet de cartes chez un joueur
	
    

public:


	Joueur(string,int);      //constructeur avec parametres
	int& getRang();			           //Accesseur de l'attribut Rang
	string getNom(); 				   //Accesseur de l'attribut Nom
	Paquet_cartes& get_player_paquet(); //Acceseur et mutateur de l'attribut Paquet
	
	
	
	//bool Couleur_exist_EnMain(Couleur); // 1 si le couleur passé en param existe en main du joueur ,0 sinon 
    //virtual Carte sortir_Carte(Carte,Couleur)=0; //retourne carte aprés selection et le supprime du paquet
	//vector<Carte> cartes_possible(Carte,Couleur); // retourne un vecteur contenant tout les cartes possible à sortir
	
	
};



#endif // JOUEUR_H
