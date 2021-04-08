#include <iostream>
#include <vector>
#include "include/Functions.h"
using namespace std;

int main()
{
    string nom;
    vector<Joueur> Players_list; //creation dune liste joueur
    for (int i = 0;i < 4;i++)
    {
        cout << "Saisir le nom d'un joueur" << i + 1 << ":\n";
        cin >> nom;
        Joueur J(nom,i+1);
        Players_list.push_back(J);
    }
    int a;
    a = rand() % 4;
    Joueur b(Players_list[a]);
    Players_list[a] = Players_list[(a + 2) % 4];
    Players_list[(a + 2) % 4] = b;               //Juste un petit melange d'equipe

    Equipe T1(Players_list[3], Players_list[1]), T2(Players_list[2],Players_list[0]);
    while (T1.getScore() < 501 || T2.getScore() < 501) {
        Table T(Players_list,T1,T2);
        int b;
        do{ T.melange();
            distribute(T,5);
            b=retour_indice(T);
        }while (b==-1);
        distribute(T,3,21,b);



    }
}
