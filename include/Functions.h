#ifndef FUNCTION_H
#define FUNCTION_H
#include "Table.h"

void distribute(Table&,int, ...);               //fonction qui distribue les cartes

int retour_indice(Table&);                      //fonction qui retourne l'indice du joueur qui prends la carte sur table

void display_cards(vector<Carte>&);             //Affichage des cartes
void affectation_Atout (vector<Carte> V);       //Affectation d'atout à un paquet
void affeectation_atout_joueur (Table T);       //Affectation d'atout à un paquet d'un joueur
void libere_joueurs_paquet(Table& T);           //effacer tout le paquet de joueur
#endif