#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H
 
#include <iostream>
#include <string>
#include "Joueur.h"

 
class Joueur_humain : public Joueur
{
 public: 
        Carte choisir_carte();
};
 
#endif