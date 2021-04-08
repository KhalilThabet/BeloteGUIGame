#include "Carte.h"
#include <iostream>
#include <stdio.h>
#include "valeur.h"
#include "couleur.h"

Carte::Carte()
{
    //ctor
}

Carte::~Carte()
{
    //dtor
}

Carte::Carte(Valeur v, Couleur c)
{
	valeur = v;
	couleur = c;
}

Couleur Carte:: getCouleur()
{
	return couleur;
}


Valeur Carte:: getValeur()
{
    return valeur;
}

bool& Carte::getAtout(){
    return atout;
}
	

int Carte::getVal_atout(){
    return val_atout;
}
int Carte::getVal_hors_atout(){
    return val_hors_atout;
}

int Carte:: compare (Carte obj,Couleur at) 
{/* fonction qui fait la comparaison entre deux carte selon l'atout ou non atout
    retourne 0 s'ils sont egaux , 1 si la carte en main est superieur a celle sur la table
    sinon -1 si la carte sur table est superieur a la carte en main*/

    
    if (couleur == at){
        if(obj.getCouleur()==at){
            int v=val_atout-obj.getVal_atout();
            if (v==0) return 0;
            else if (v>0) return 1;
            else return -1;
        }
        else if (obj.getCouleur() != at){
            int v=val_atout-obj.getVal_hors_atout();
            if (v==0) return 0;
            else if (v>0) return 1;
            else return -1;
        }
    }
    else if (couleur != at) {
        if (obj.getCouleur()==at){
            int v=val_hors_atout-obj.getVal_atout();
            if (v==0) return 0;
            else if (v>0) return 1;
            else return -1;
        }
        else if (obj.getCouleur() != at){
            int v=val_hors_atout-obj.getVal_hors_atout();
            if (v==0) return 0;
            else if (v>0) return 1;
            else return -1;
        }
    }
}