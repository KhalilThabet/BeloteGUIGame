#ifndef JOUEUR_MACHINE_H
#define JOUEUR_MACHINE_H
 
#include <iostream>
#include <string>
#include "Joueur.h"

 
class Joueur_machine : public Joueur
{
    public: 
            Carte choisir_carte();
};
 
#endif