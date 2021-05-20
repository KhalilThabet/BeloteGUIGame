#ifndef TABLE_H
#define TABLE_H
#include "Equipe.h"


using namespace std ;

class Table
//Documentation
{
    vector<Carte> CardsOnTable;                     //Conteneur correspondant aux 4 cartes mise par chaque joueur sur la table
                                              
    int nbr_pli = 8;                                //Nombre de pli durant une manche
    vector<Carte> AllCards;                         //Conteneur contenant toutes les cartes du jeu
    vector<Joueur> Joueurs;                         //Conteneur contenant les 4 joueurs qui sont en train de jouer
    Equipe T1,T2;                                   //Deux objets de classe equipe qui contiennent les deux equipes


public:

    Table(vector<Joueur>&,Equipe&,Equipe&);         //Constructure avec parametres

    vector<Carte>& getAllCards();                   //Accesseur attribut AllCards
    void setAllCards(vector<Carte>& C);             //Mutateur attribut AllCards
    vector<Joueur>& getJoueurs();                   //Accesseur attribut Joueur
    void setJoueurs(vector<Joueur>& J);             //Mutateur attribut Joueur
    Equipe& getT1();                                //Accesseur attribut T1
    void setT1(Equipe& T);                          //Mutateur attribut T1

    Equipe& getT2();                                //Accesseur attribut T2
    void setT2(Equipe& T);                          //Mutateur attribut T2
    vector<Carte>& getCardsOnTable();               //Accesseur attribut CardsOnTable
    void setCardsOnTable(vector<Carte>& C);         //Mutateur attribut CardsONTable
    void melange();                                 //Melange des cartes du vecteur AllCards
    Carte compareTableCards(string);                //Compare les carte sur table
    void Score(string atout,int b);                 //Calculer score de chaque equipe
    int joueur_gagnant(string atou,int b);          //decider le joueur gagnant
    int somme_score(string at);                     //Calculer la somme de score avant l'affecter au equipe gagnant
      

};

#endif // TABLE_H
