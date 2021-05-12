#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
// #include "include/Joueur.h"
#include "./src/Joueur.cpp"
#include "./src/Equipe.cpp"
#include "./src/Table.cpp"
using namespace std;
void distribute(Table& T,int NumberOfCardToDistribute,int StartingCardPosition=1, int IndexOfFirstPlayer=0)
{	//function cards distribution
	 
 	int j = IndexOfFirstPlayer ;		 //Designe le premier joueur a etres servi
 	vector<Carte> SendingPacket = {};	 //Vecteur qui sert de conteneur temporaire au paquet des joueurs
	cout<<"\n"<<NumberOfCardToDistribute<<" "<<StartingCardPosition<<" "<<IndexOfFirstPlayer<<endl;
	if (SendingPacket.empty()) cout <<"Vide"<<endl;

 	for (int i = StartingCardPosition ; i < 33 ; i++) {		//Distribution de cartes a partir de l'indice donnee
 		if (i % NumberOfCardToDistribute == 0) 				//Arrivant au nombre desirer de carte par joueur
															//Rempli les attributs paquet du joueur d'indice j
		{   
            cout<<" Card number : "<<i<<endl;
			SendingPacket.push_back(T.getAllCards()[i-1]);
            for(int k=0;k<SendingPacket.size();k++){
                cout<<SendingPacket[k].getValeur()<<endl;
            }
			((T.setJoueurs()[j]).set_player_paquet()).setPaquet(SendingPacket);
			SendingPacket.clear();
			j += 1;
			j = j % 4;
		}
		else {
			SendingPacket.push_back(T.getAllCards()[i-1]);
			

		}
		
	}
}
int retour_indice(Table& T){
	/* fonction qui retourne l'indice du joueur qui a accepter
		la carte mise sur la table */
	char reponse;
	cout<<"Entering Retour Indice"<<endl;
	for(int i=0;i<4;i++)
	{	

		cout << "Carte de valeur:" << (T.getAllCards()[20]).getValeur()<<"\n" <<"Carte de couleur:" << (T.getAllCards()[20]).getCouleur() <<endl;
		cout <<"Tapez : Y  vous voulez saisir la carte sinon n'importe quel autre lettre";
		reponse=getch();

		if (reponse == 'Y')
		{	
			
			for (int j=0;j<32;j++)
			{
				if ((T.getAllCards()[j]).getCouleur() == (T.getAllCards()[20]).getCouleur())
					(T.setAllCards()[j]).setAtout()=1;
			}
			if (i==3 || i==1)
				(T.setT1()).setatout()=0;
			
			else (T.setT2()).setatout()=1;

			return i;
		
		}
		
	}
	return -1;
	
}
int main()
{
    string nom;
    cout<<"Nom created"<<endl;
    vector<Joueur> Players_list;
    cout<<"Joueur Created"<<endl;
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
    // for (int i=0;i<4;i++){
    //     cout<<Players_list[i].getRang()<<" ";
    // }
    // for (int i=0;i<4;i++){
    //     vector<Carte> CartesJoueurs=Players_list[i].get_player_paquet().getPaquet();
    //     if (!CartesJoueurs.empty()){
    //         for(int j=0;j<CartesJoueurs.size();j++){
    //             cout<<CartesJoueurs[j].getValeur()<<endl;
    //         }
    //     }
    //     else cout<<"Empty for the Player"<<i<<"\n";
    // }

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
        while (T1.getScore() < 501 || T2.getScore() < 501) {

            Table T(Players_list,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
            cout<<T.getAllCards().size();
            int b;
            int i=0;
            do{
                T.melange();
                distribute(T,5);            //distribue 5 cartes a chacun des joueurs
                b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
            }while (b==-1);
            distribute(T,3,21,b); 
            break;
            }
            break;}}          //Distribue les reste du paquet aux joueurs commencant par le joueur consenttnt a prendre la carte sur la table
            // for(int i=0;i<8;i++){
            //     for(int j=0;j<4;j++){
            //         Players_list[j].cartes_possibles();//Affiche les cartes possibles dans la main du joueur
            //         Carte carte_choisit=Players_list[j].choisir_carte();//Donne au joueur de choisir une carte parmis les cartes possibles;//un appel a la methode carte methode est necessaire a cette methde
            //         Players_list[j].sortir_carte(T,carte_choisit);
            //         T.Score(); // Affecte les scores necessaires a chaque equipe(necessite de remplacer int& get score par un mutateur int& setScore)
            //         //necessite de creation d'un methode qui fait la comparaison entre les 4 cartes du vecteur CardsOnTable
            //     }
            // }

//         cout<<"Would you like to play another game?"<<endl;
//         string y;
//         cin>> y;
//         if (y=="No") break;
//         }
//         break;
// }