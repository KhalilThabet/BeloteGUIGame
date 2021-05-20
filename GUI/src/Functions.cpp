#include <conio.h>
#include <cstdio>
#include <QGridLayout>
#include <QString>
#include <QEventLoop>
#include <QLineEdit>
#include <string>
#include "./include/Functions.h"
using namespace std;

void distribute(Table& T,int NumberOfCardToDistribute,int ending,int StartingCardPosition=1, int IndexOfFirstPlayer=0)
{	//function cards distribution
	 
 	int j = IndexOfFirstPlayer ;		 //Designe le premier joueur a etres servi
 	vector<Carte> SendingPacket = {};	 //Vecteur qui sert de conteneur temporaire au paquet des joueur
 	for (int i = StartingCardPosition ; i < ending ; i++) {		//Distribution de cartes a partir de l'indice donnee
 		if ((i-StartingCardPosition+1) % NumberOfCardToDistribute == 0) 				//Arrivant au nombre desirer de carte par joueur
															//Rempli les attributs paquet du joueur d'indice j
		{   
			SendingPacket.push_back(T.getAllCards()[i-1]);
           
			((T.setJoueurs()[j]).set_player_paquet()).setPaquet().insert(((T.setJoueurs()[j]).set_player_paquet()).setPaquet().end(),SendingPacket.begin(),SendingPacket.end());
			SendingPacket.clear();
			j += 1;
			j = j % 4;
		}
		else {
			SendingPacket.push_back(T.getAllCards()[i-1]);
			

		}
		
	}
}

void affectation_Atout (Table& T,vector<Carte>& V){		
												//Changer la valeur d'atout de chaque Carte dans V à 1
	for (int j=0;j<V.size();j++)
				{
					if (((string)((V[j]).getCouleur()) == (string)(T.getAllCards()[20]).getCouleur()))  //identifier le carte de couleur egale à celle de l'atout
						{
							(V[j]).setAtout()=1;															//Canger la valeur de l'atout
						}
				}
}
void affeectation_atout_joueur (Table& T)															//affectation de l'atout de paquet de chaque joueur
{
	for (int i=0; i<4;i++)																			//parcour de vector de joueur
	{
		affectation_Atout (T,T.setJoueurs()[i].set_player_paquet().setPaquet());								//Appel à la fonction Affectation_atout 
	}
}
int verify(string s,int i){
	if (s=="YES") return i;
	else return -1;
}
int retour_indice(Table& T,QGridLayout* layout){
		
																			//Retourne l'indice de joueur qui prend l'atout 
	int j=1;
	// auto verif=verify;
	// QEventLoop* loop=new QEventLoop;
	// for(int i=0;i<4;i++) //Parcour des joueurs en leur proposant la carte
	// {	QLabel* label=new QLabel(QString::fromStdString((T.getAllCards()[20]).getValeur()+" "+(T.getAllCards()[20]).getCouleur())) ;
	// 	QLineEdit* Response=new QLineEdit;
	// 	Response->setPlaceholderText("Yes/No");
	// 	layout->addWidget(label,3,6);
	// 	layout->addWidget(Response,4,6);
	// 	QObject::connect(Response,&QLineEdit::editingFinished,[Response,label,loop,i,&j,&T,verif](){delete Response;delete label;loop->exit();j=verif(Response->displayText().toLocal8Bit().constData(),i);});
		
		
	// }
	
	
	// loop->exec();
	affectation_Atout (T,T.setAllCards());													//changer l'atout tout les cartes de Table
				
	if (j==3 || j==1){																		//Changer l'atout de l'equipe 1
		T.setT1().setatout()=1;
	}
	
	else {																					//changer l'atout de l'equipe 2
		T.setT2().setatout()=1;
	}
	return j;
			
			
		

	
}

