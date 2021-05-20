#ifndef FUNCTION_H
#define FUNCTION_H
#include "Table.h"

void distribute(Table&,int, ...);//fonction qui distribue les cartes

int retour_indice(Table&);//fonction qui retourne l'indice du joueur qui prends la carte sur table

void display_cards(vector<Carte>);
void affeectation_atout_joueur (Table& T);
void affectation_Atout (Table& T,vector<Carte>& V);
#endif