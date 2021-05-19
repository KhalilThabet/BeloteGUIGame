#ifndef CARTE_H_
#define CARTE_H_
#include<string>
using namespace std;

class Carte 
                                        //Classe qui definit les proprietes caracteristique de chaque carte durant le jeu
{
    int id;                             
	string couleur;                     //types possibles pour une carte 
	string valeur;                      //valeurs possibles pour une carte
    bool atout = 0;                     //0 si couleur==atout ,sinon 1
    int acces = 1;                      //1 si le joueur peut sortir la carte(disponible) ,0 sinon
    int val_atout;                      //valeur d'une carte en atout
	int val_hors_atout;                 //valeur d'une carte hors atout


public:

    Carte();                            //Constructeur sans parametres
    Carte(string,string,int,int);       //Constructeur avec parametres
    Carte(Carte*);                      //Constructeur de recopie 

	string& getCouleur();               //retourne l'attribut couleur
	void setCouleur(string& s);         //Mutateur de l'atribut Couleur

    string& getValeur();                //retourne l'attribut valeur
    void setValeur(string& s) ;         //Mutateur de l'attrbut valeur   

    bool& getAtout();                   //retourne l'attribut booleen atout
    void setAtout(int a);               //Mutateur de l'attribut Atout

    int& getAcces();                    //retourne l'attribut Acces
    void setAcces(int& a);              //Mutateur de l'attribut Acces

    int& getVal_atout();                //retourne la valeur de la carte en atout
    void setVal_atout(int& a);          //Mutateur de la valeur de la carte en atout

    int& getVal_hors_atout();           //retourne la valeur de la carte hors atout
    void setVal_hors_atout(int& a);     //Mutateur de la valeur de la carte hors atout
    void operator=(Carte);              //surcharge de l'operateur egale
	bool operator==(Carte);             //surcharge de l'operateur verification de l'egalité
	
	int compare (Carte,string);         //Compare entre deux cartes //atout=couleur
};

#endif