#include "./src/Functions.cpp"
#include "./include/Joueur.h"
#include "./src/joueur.cpp"
#include "./src/carte.cpp"
#include "./src/Table.cpp"
#include "./src/paquet_cartes.cpp"
#include "./src/Equipe.cpp"
#include <ctime>
using namespace std;


int main()
{
    unsigned seed = time(0);                                                            //variable de type unsigned utilisé dans srand
    srand(seed);                                                                        //Assurer que les valuers aleatoire ne se repete pas
    string nom;
    cout<<"Bienvenue au jeu Belote "<<endl;
    vector<Joueur> Players_list;                                                        //Creation de vector de joueurs
    for (int i = 0;i < 4;i++)                                                           //parcour le vector de joueurs
    {   cout<<"Joueur : "<<i<<endl;
        cout << "Saisir le nom d'un joueur" << i + 1 << ":\n";                          //Demander à chaquer joueur de ecrier son nom
        cin >> nom;                                                                     //Affectation de nom joueur
        Joueur J(nom,i+1);                                                              //Creation d'un joueur avec son nom est rang
        Players_list.push_back(J);                                                      //Ajout de joueur au vector de joueur
    }

    int a;
    a = rand() % 4;                                                                     //un entier entre 0 et 4
    cout<<"\n RandomValue a :"<<a<<endl;
    Joueur temp(Players_list[a]);                                                       //Creation d'un objet temporaire joueur avec le constructeur de recopie
    Players_list[a] = Players_list[(a + 2) % 4];                                        //Echanger deux joueurs dans le vecteur Players_list aleatoirement avec l'operator=
    Players_list[(a + 2) % 4] = temp;                                                   //Juste un petit melange d'equipe
    for (int i=0;i<4;i++){
        cout<<Players_list[i].getNom()<<" ";                                            //Affichier le nom des joueurs apres melange
    }
    Equipe T1(Players_list[3], Players_list[1]), T2(Players_list[2],Players_list[0]);   //Affectation des joueurs melanger dans le vecteur a des equipes
    T1.afficheTeam();                                                                   //Affichier les joueurs de premier equipe
    T2.afficheTeam();                                                                   //Affichier les joueurs de deuxieme equipe
    cout<<"\nTeam 1 Score :"<<T1.getScore()<<" Team 2 : "<<T2.getScore();               //Affichier le score de chaque equipe


    while (1){                                                                          //Le boucle qui contient tout le jeu
        while (T1.getScore() < 200 && T2.getScore() < 200) {                            //Le boucle qui contient le match

            Table T(Players_list,T1,T2);                                                //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
            cout<<T.getAllCards().size();
            int b;
            int i=0;
            do{
                libere_joueurs_paquet(T);
                T.melange();
                distribute(T,5,21);                                                     //distribue 5 cartes a chacun des joueurs
                //affeectation_atout_joueur (T);                                          //changer l'atout dans les paquets de tout les joueurs
                b=retour_indice(T);                                                     //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
            }while (b==-1);                                                             //Boucler jusqu'à un joueur prend l'atout
            distribute(T,3,33,21,b); 
            cout<<"***************************************************************************************************************************************************\n";
            affeectation_atout_joueur (T);                                              //changer l'atout dans les paquets de tout les joueurs

       
            for(int i=0;i<8;i++){                                                       //Boucle pour un pli
                for(int j=0;j<4;j++){                                                   //Boucle pour un manche
                    int a=(j+b)%4;
                    cout << "les cartes possible pour le joueur "<<a<<" dans la "<<i+1<<" eme manche  : \n";
                    vector<Carte> C=T.getJoueurs()[a].cartes_possible(T.getCardsOnTable(),(T.getAllCards()[20]).getCouleur());//Affiche les cartes possibles dans la main du joueur                    
                    display_cards(C);                                                   //affichier au joueurs les cartes possible 
                    T.getJoueurs()[a].sortir_carte(T.getCardsOnTable(),T.getJoueurs()[a].choisir_carte(C));//Joueur joue le cartes qu'il veut dans l'ensemble de celle possible
                    cout<< "les cartes sur la table \n";
                    display_cards(T.getCardsOnTable());                                 //Affichier les cartes déja joué
                }
                T.Score((T.getAllCards()[20]).getCouleur(),b);                          //Affecter le score de manche au equipe gagnant
                vector<Carte>& V=T.getCardsOnTable();
                V.clear();                                                              //vider la table
                b=T.joueur_gagnant((T.getAllCards()[20]).getCouleur(),b);               //Le joueur gangnant est celle qui commence dans le manche suivant
            }
        }

        cout<<"Voullez vous jouer une autre match?"<<endl;                              //Demmende aux joueurs si ils vont continuer à jouer
        string y;
        cin>> y;
        if (y=="No") break;
    }
    return 0;
}