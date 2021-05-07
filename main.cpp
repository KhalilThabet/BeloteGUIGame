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
    Joueur temp(Players_list[a]);  //construcateur de recopie                    //Creation d'un objet temporaire joueur
    Players_list[a] = Players_list[(a + 2) % 4];//operator=       //Echanger deux joueurs dans le vecteur Players_list aleatoirement
    Players_list[(a + 2) % 4] = temp;                  //Juste un petit melange d'equipe

    Equipe T1(Players_list[3], Players_list[1]), T2(Players_list[2],Players_list[0]); //Affectation des joueurs melanger dans le vecteur a des equipes
    while (1){
        while (T1.getScore() < 501 || T2.getScore() < 501) {

            Table T(Players_list,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
            int b;
            do{ T.melange();
                distribute(T,5);            //distribue 5 cartes a chacun des joueurs
                b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
            }while (b==-1);
            distribute(T,3,21,b);           //Distribue les reste du paquet aux joueurs commencant par le joueur consenttnt a prendre la carte sur la table
            for(int i=0;i<8;i++){
                for(int j=0;j<4;j++){
                    Players_list[j].cartes_possibles();//Affiche les cartes possibles dans la main du joueur
                    Carte carte_choisit=Players_list[j].choisir_carte();//Donne au joueur de choisir une carte parmis les cartes possibles;//un appel a la methode carte methode est necessaire a cette methde
                    Players_list[j].sortir_carte(T,carte_choisit);
                    T.Score(); // Affecte les scores necessaires a chaque equipe(necessite de remplacer int& get score par un mutateur int& setScore)
                    //necessite de creation d'un methode qui fait la comparaison entre les 4 cartes du vecteur CardsOnTable
                }
            }

        cout<<"Would you like to play another game?"<<endl;
        string y;
        cin>> y;
        if (y=="No") break;
        }
}
