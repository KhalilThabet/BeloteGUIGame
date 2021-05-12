#ifndef FUNCTION_H
#define FUNCTION_H
#include "Table.h"
#include "Equipe.h"
#include "Joueur.h"
#include "Carte.h"

void distribute(Table&,int, ...);//fonction qui distribue les cartes

int retour_indice(Table&);//fonction qui retourne l'indice du joueur qui prends la carte sur table

#endif