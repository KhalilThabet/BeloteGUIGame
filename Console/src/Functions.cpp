#include "../include/Table.h"
#include <conio.h>
#include <cstdio>
using namespace std;

void distribute(Table& T,int NumberOfCardToDistribute,int ending,int StartingCardPosition=1, int IndexOfFirstPlayer=0)	//function cards distribution
{	
	 
 	int j = IndexOfFirstPlayer ;		 															//Designe le premier joueur a etres servi
 	vector<Carte> SendingPacket = {};	 															//Vecteur qui sert de conteneur temporaire au paquet des joueur
 	for (int i = StartingCardPosition ; i < ending ; i++) {											//Distribution de cartes a partir de l'indice donnee
 		if ((i-StartingCardPosition+1) % NumberOfCardToDistribute == 0) 							//Arrivant au nombre desirer de carte par joueur															                        //Rempli les attributs paquet du joueur d'indice j
		{   
			
			SendingPacket.push_back(T.getAllCards()[i-1]);											//Ajout de dernier Carte
			(T.getJoueurs()[j]).set_player_paquet(SendingPacket);									//affectation de carte au joueurs
			SendingPacket.clear();																	//libere SendingPacket

			j += 1;																					//Passer a un autre joueur
			j = j % 4;																				//Assure qui J rester inferieur à 4
		}
		else {
			SendingPacket.push_back(T.getAllCards()[i-1]);											//Ajout de cartes avant l'affecteé au joueur
			

		}
		
	}
}
void affectation_Atout (Table& T,vector<Carte>& V){													//Changer la valeur d'atout de chaque Carte dans V à 1
for (int j=0;j<V.size();j++)
			{
				if (((string)((V[j]).getCouleur()) == (string)(T.getAllCards()[20]).getCouleur()))  //identifier le carte de couleur egale à celle de l'atout
					{
						(V[j]).setAtout(1);															//Canger la valeur de l'atout
					}
			}
}
void affeectation_atout_joueur (Table& T)															//affectation de l'atout de paquet de chaque joueur
{
	for (int i=0; i<4;i++)																			//parcour de vector de joueur
	{
		affectation_Atout (T,T.getJoueurs()[i].get_player_paquet());								//Appel à la fonction Affectation_atout 
	}
}
int retour_indice(Table& T ){																		//fonction qui retourne l'indice du joueur qui a accepter la carte mise sur la table 
	
	char reponse;
	int a=1 ;
	cout<<"Entering Retour Indice"<<endl;
	for(int i=0;i<4;i++) 																			//Parcour des joueurs en leur proposant la carte
	{	

		cout << "Carte de valeur:" << (T.getAllCards()[20]).getValeur()<<"\n";
		cout << "Carte de couleur:" << (T.getAllCards()[20]).getCouleur()<<"\n";
		cout <<"Joueur "<<i+1;
		cout<<" :   Tapez Y Si vous voulez prendre la carte sinon n'importe quel autre lettre\n"; 	//Demander si le jouuer veut prendre la carte d'atout 
		reponse=getch();																			//Prendre le reponse de joueur 
		if (toupper(reponse) == 'Y')																//verifier si le reponse est oui  
		{	
			
			affectation_Atout (T,T.getAllCards());													//changer l'atout tout les cartes de Table
			
			if (i==3 || i==1){																		//Changer l'atout de l'equipe 1
				(T.getT1()).setatout(a);
			}
			
			else {																					//changer l'atout de l'equipe 2
				(T.getT2()).setatout(a);
			}

			return i;																				//Retourne l'indice de joueur qui prend l'atout 
		
		}
		
	}
	return -1;																						//Retourne -1 si aucun joueur ne veut prendre l'atout pour redistribuer les cartes
	
}

void display_cards(vector<Carte>& V){																//Fonction pour affichier les cartes
	cout<<"display Cards\n";
	cout<<"V size :"<<V.size()<<"\n";																//Affichier le size de Paquet V
	for(int i=0;i<V.size();i++){																	//Parcour le paquet
		cout<<V[i].getCouleur()<<" ";																//Affichier le couleur d'une carte 
		cout<<V[i].getValeur()<<" ";																//Affichier le valeur d'une carte
		cout<<V[i].getAtout()<<" "<<endl;															//Affichier le valeur d'atout d'une carte
	}
	cout<<"\n\n";
}															
void libere_joueurs_paquet(Table& T)																//fonction pour liberer le paquet d'un joueur
{
    for(int i= 0;i<4;i++)																			//parcour le vector de joueurs
    T.getJoueurs()[i].get_player_paquet().clear();													//effacer tout les cartes de joueurs
}
