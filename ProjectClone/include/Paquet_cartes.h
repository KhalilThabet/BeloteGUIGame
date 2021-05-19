#ifndef PAQUET_CARTES_H_
#define PAQUET_CARTES_H_
#include "Carte.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Paquet_cartes
{
    vector<Carte> Paquet;                       /*Attribut du paquet de carte 
                                                  contenant les cartes d'un joueur*/

    public:
            Paquet_cartes();
            Paquet_cartes(vector<Carte>&);      //Creation de l'objet paquet de cartes
            // ~Paquet_cartes();                   //Destructeur du paquet de cartes
            void operator=(Paquet_cartes);

            vector<Carte> getPaquet();         //Accesseur a l'aatribut Paquet
            vector<Carte>& setPaquet();     //Mutateur de l'attribut Paquet

};


#endif