#ifndef PAQUET_CARTES_H_
#define PAQUET_CARTES_H_
#include "Carte.h"
#include <vector>
#include <iostream>
using namespace std;
class Paquet_cartes
{
    vector<Carte> Paquet;                           //Attribut du paquet de carte contenant les cartes d'un joueur
                                                  

    public:
            Paquet_cartes();
            Paquet_cartes(vector<Carte>&);          //Creation de l'objet paquet de cartes
                             
            void operator=(Paquet_cartes);          //surcharge de l'operatuer egale

            vector<Carte>& getPaquet();             //Accesseur a l'aatribut Paquet
            void setPaquet(vector<Carte>& C);       //Mutateur de l'attribut Paquet

};


#endif