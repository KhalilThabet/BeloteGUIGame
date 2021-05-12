#include "../include/Table.h"
#include <conio.h>
#include <cstdio>
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
			((T.setJoueurs()[j]).set_player_paquet()).setPaquet()=SendingPacket;
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
	for(int i=0;i<4;i++) //Parcour des joueurs en leur proposant la carte
	{	

		cout << "Carte de valeur:" << (T.getAllCards()[20]).getValeur()<<"\n" <<"Carte de couleur:" << (T.getAllCards()[20]).getCouleur() <<endl;
		cout <<"Tapez : Y  vous voulez saisir la carte sinon n'importe quel autre lettre";
		reponse=getch();

		if (toupper(reponse) == 'Y')
		{	
			
			for (int j=0;j<32;j++)
			{
				if ((T.getAllCards()[j]).getCouleur() == (T.getAllCards()[20]).getCouleur())
					(T.setAllCards()[j]).setAtout()=1;
			}
			if (i==3 || i==1)
				(T.setT1()).setatout()=1;
			
			else (T.setT2()).setatout()=1;

			return i;
		
		}
		
	}
	return -1;
	
}