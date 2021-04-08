#ifndef CARTE_H_
#define CARTE_H_
#include "Couleur.h"
#include "Valeur.h"


class Carte 
//Classe qui definit les proprietes caracteristique de chaque carte durant le jeu
{
	string couleur;                  //types possibles pour une carte 
	string valeur;                   //valeurs possibles pour une carte
    bool atout = 0;                  //0 si couleur==atout ,sinon 1
    bool accee = 1;                  //1 si le joueur peut sortir la carte(disponible) ,0 sinon
    int val_atout;                   // valeur d'une carte en atout
	int val_hors_atout;              // valeur d'une carte hors atout


public:

    Carte();                             //Constructeur par default
    Carte(string val,string coul);      //Constructeur avec parametres
    ~Carte();

	string& getCouleur();                //retourne l'attribut couleur
	string& getValeur();                  //retourne l'attribut valeur
    bool& getAtout();                    //retourne l'attribut booleen atout
    int& getVal_atout();                  //retourne la valeur de la carte en atout
    int& getVal_hors_atout();             //retourne la valeur de la carte en hors atout
	
	
	int compare (Carte obj ,string at); //Compare entre deux cartes
};

#endif