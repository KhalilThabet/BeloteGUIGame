#include "Paquet_cartes.h"
#include <stdio.h>
#include <stdlib.h>

Paquet_cartes::Paquet_cartes(vector<Carte>& receivedCards)
{
    Paquet = receivedCards;
}


Paquet_cartes::~Paquet_cartes(){}

vector<Carte>& Paquet_cartes::getPaquet() {
    return Paquet;
}


void Paquet_cartes::setPaquet(vector<Carte>& A) {
    Paquet = A;
}