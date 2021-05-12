#ifndef CARTE_H_
#define CARTE_H_
#include<string>
using namespace std;

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

    Carte();
    Carte(string,string,int,int);      //Constructeur avec parametres
    Carte(Carte*);

	string getCouleur();                //retourne l'attribut couleur
	string& setCouleur();  

    string getValeur(); //retourne l'attribut valeur
    string& setValeur() ;             

    bool getAtout();                    //retourne l'attribut booleen atout
    bool& setAtout();

    int getVal_atout();                  //retourne la valeur de la carte en atout
    int& setVal_atout();

    int getVal_hors_atout();             //retourne la valeur de la carte en hors atout
    int& setVal_hors_atout();
    void operator=(Carte C);
	
	
	int compare (Carte,string); //Compare entre deux cartes //atout=couleur
};

#endif