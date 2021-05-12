#include "../include/Paquet_cartes.h"
#include "Carte.cpp"
#include <stdio.h>
#include <stdlib.h>
Paquet_cartes::Paquet_cartes(){
    Paquet ={};
}
Paquet_cartes::Paquet_cartes(vector<Carte>& receivedCards)
{
    Paquet = receivedCards;
}


// Paquet_cartes::~Paquet_cartes(){
//     delete [] &Paquet;
// }

vector<Carte> Paquet_cartes::getPaquet() {
    return Paquet;
}


void Paquet_cartes::setPaquet(vector<Carte>& A) {
    Paquet = A;
}

void Paquet_cartes::operator=(Paquet_cartes Cartes){
    Paquet=Cartes.Paquet;
}
