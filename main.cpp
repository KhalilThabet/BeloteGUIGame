#include <iostream>
#include <vector>
#include "include/Functions.h"
using namespace std;

int main()
{
    string nom;
    vector<Joueur> Players_list;                        //creation d'une liste joueur
    for (int i = 0;i < 4;i++)
    {
        cout << "Saisir le nom d'un joueur" << i + 1 << ":\n";
        cin >> nom;
        Joueur J(nom,i+1);
        Players_list.push_back(J);
    }

    int a;
    a = rand() % 4;                                 //un entier entre 0 et 4
    Joueur temp(Players_list[a]);                      //Creation d'un objet temporaire joueur
    Players_list[a] = Players_list[(a + 2) % 4];       //Echanger deux joueurs dans le vecteur Players_list aleatoirement
    Players_list[(a + 2) % 4] = temp;                  //Juste un petit melange d'equipe

    Equipe T1(Players_list[3], Players_list[1]), T2(Players_list[2],Players_list[0]); //Affectation des joueurs melanger dans le vecteur a des equipes

    while (T1.getScore() < 501 || T2.getScore() < 501) {

        Table T(Players_list,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
        int b;
        do{ T.melange();
            distribute(T,5);            //distribue 5 cartes a chacun des joueurs
            b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
        }while (b==-1);
        distribute(T,3,21,b);           //Distribue les reste du paquet aux joueurs commencant par le joueur consenttnt a prendre la carte sur la table



    }
}
