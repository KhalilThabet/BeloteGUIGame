#ifndef TABLE_H
#define TABLE_H
#include <vector> 
#include "Carte.h"
#include "Joueur.h"
#include "Equipe.h"


using namespace std ;

class Table
//Documentation
{
    vector<Carte> CardsOnTable;             /*Conteneur correspondant aux 4 cartes 
                                              mise par chaque joueur sur la table*/
    int nbr_pli = 8;                        //Nombre de pli durant une manche
    vector<Carte> AllCards;                 //Conteneur contenant toutes les cartes du jeu
    vector<Joueur> Joueurs;                 //Conteneur contenant les 4 joueurs qui sont en train de jouer
    friend class Carte;
    Equipe T1,T2;                           //Deux objets de classe equipe qui contiennent les deux equipes


public:

    Table(vector<Joueur>,Equipe,Equipe);

    vector<Carte>& getAllCards();            //Accesseur attribut AllCards
    vector<Joueur>& getJoueurs();             //Accesseur attribut Joueurs
    Equipe getT1();                         //Accesseur Attribut T1
    Equipe getT2();                         //Accesseur Attribut T2
    void melange();                  //Melange des cartes du vecteur AllCards

        

};

#endif // TABLE_H
