#include "./src/Functions.cpp"
#include "./include/Joueur.h"
#include "./src/joueur.cpp"
#include "./src/carte.cpp"
#include "./src/Table.cpp"
#include "./src/paquet_cartes.cpp"
#include "./src/Equipe.cpp"
using namespace std;


int main()
{
    string nom;
    cout<<"Object Nom created"<<endl;
    vector<Joueur> Players_list;
    cout<<"Object Joueur Created"<<endl;
    for (int i = 0;i < 4;i++)
    {   cout<<"i : "<<i<<endl;
        cout << "Saisir le nom d'un joueur" << i + 1 << ":\n";
        cin >> nom;
        Joueur J(nom,i+1);
        Players_list.push_back(J);
    }
    for (int i=0;i<4;i++){
        cout<<Players_list[i].getNom()<<" ";
    }
    for (int i=0;i<4;i++){
        cout<<Players_list[i].getRang()<<" ";
    }

    int a;
    a = rand() % 4;                                 //un entier entre 0 et 4
    cout<<"\n RandomValue a :"<<a<<endl;
    Joueur temp(Players_list[a]);  //construcateur de recopie                    //Creation d'un objet temporaire joueur
    Players_list[a] = Players_list[(a + 2) % 4];//operator=       //Echanger deux joueurs dans le vecteur Players_list aleatoirement
    Players_list[(a + 2) % 4] = temp;                  //Juste un petit melange d'equipe
    for (int i=0;i<4;i++){
        cout<<Players_list[i].getNom()<<" ";
    }
    Equipe T1(Players_list[3], Players_list[1]), T2(Players_list[2],Players_list[0]); //Affectation des joueurs melanger dans le vecteur a des equipes
    T1.afficheTeam();
    T2.afficheTeam();
    cout<<"\nTeam 1 Score :"<<T1.getScore()<<" Team 2 : "<<T2.getScore();


    while (1){
        while (T1.getScore() < 200 && T2.getScore() < 200) {

            Table T(Players_list,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
            cout<<T.getAllCards().size();
            int b;
            int i=0;
            do{
                T.melange();
                distribute(T,5,21);            //distribue 5 cartes a chacun des joueurs
                b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
            }while (b==-1);
            distribute(T,3,33,21,b); 
            cout<<"********************\n";
            for (int i=0;i<T.getJoueurs().size();i++){
                display_cards(T.getJoueurs()[i].get_player_paquet().getPaquet());
            }        
            for(int i=0;i<8;i++){
                for(int j=0;j<4;j++){
                    vector<Carte> C=T.getJoueurs()[i].cartes_possible(T.getCardsOnTable(),"trefle");//Affiche les cartes possibles dans la main du joueur                    
                    display_cards(C);
                    T.getJoueurs()[i].sortir_carte(T.setCardsOnTable(),T.getJoueurs()[i].choisir_carte(C));
                    //T.Score(); // Affecte les scores necessaires a chaque equipe(necessite de remplacer int& get score par un mutateur int& setScore)
                    //necessite de creation d'un methode qui fait la comparaison entre les 4 cartes du vecteur CardsOnTable
                }
                display_cards(T.getCardsOnTable());
            }
        }

        cout<<"Would you like to play another game?"<<endl;
        string y;
        cin>> y;
        if (y=="No") break;
    }
    return 0;
}