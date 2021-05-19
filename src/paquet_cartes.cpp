#include "../include/Paquet_cartes.h"
Paquet_cartes::Paquet_cartes(){
    Paquet ={};
}
Paquet_cartes::Paquet_cartes(vector<Carte>& receivedCards)
{
    Paquet = receivedCards;
}


vector<Carte>& Paquet_cartes::getPaquet() {
    return Paquet;
}


void Paquet_cartes::setPaquet(vector<Carte>& C) {
    Paquet=C;
}

void Paquet_cartes::operator=(Paquet_cartes Cartes){
    Paquet=Cartes.Paquet;
}
