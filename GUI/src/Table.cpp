#include "../include/Table.h"
#include <fstream>
#include <ctime>
Table::Table(vector<Joueur>& Players_list,Equipe& team1,Equipe& team2)
{	
	Equipe T1=team1;
	Equipe T2=team2;
	Joueurs = Players_list;
	
	ifstream sortie("C:/Users/Khali/OneDrive/Bureau/SchoolProject/src/Belote.txt");		//Base de donne contenant les cartes du jeu
	if (sortie)
	{
		for (int i = 0;i < 32;i++)
		{
			Carte temp;					//Creation d'un objet temporaire Carte 
										//pour stocker les informations sortante
										//de la base de donnee
										
			sortie >> temp.setCouleur();
			sortie >> temp.setValeur();
			sortie >> temp.setVal_atout();
			sortie >> temp.setVal_hors_atout();
			sortie >> temp.setAddress0();
			sortie >> temp.setAddress90();

			AllCards.push_back(temp);
		}
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier en lecture" << '\n';
	}
	
}


vector<Carte> Table::getAllCards() {		//Accesseur Attribut AllCards
	return AllCards;
}
vector<Carte>& Table::setAllCards() {		//Accesseur Attribut AllCards
	return AllCards;
}
vector<Joueur>  Table::getJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}
vector<Joueur>&  Table::setJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}


Equipe Table::getT1()						//Accesseur Attribut T1
{
	return T1;
}
Equipe& Table::setT1()
{
	return T1;
}


Equipe Table::getT2()						//Accesseur Attribut T2
{
	return T2;
}
Equipe& Table::setT2()						//Accesseur Attribut T2
{
	return T2;
}

void Table::melange()						//Melange des cartes du vecteur AllCards
{
	int b;
	for (int a = 0;a < 32;a++)
    {   unsigned b=time(0)% 32;
		Carte C ;
		C = AllCards[a];
		AllCards[a] = AllCards[b];
		AllCards[b] = C;
	}

}

Carte Table::compareTableCards(string atout){
	Carte Highest_Card=CardsOnTable[0];
	for(int i=1;i<4;i++){
		if (CardsOnTable[i].compare(Highest_Card,atout)>0){
			Highest_Card=CardsOnTable[i];
		}
	}
	return Highest_Card;
}

vector<Carte> Table::getCardsOnTable(){
	return CardsOnTable;
}
vector<Carte>& Table::setCardsOnTable(){
	return CardsOnTable;
}


int Table:: joueur_gagnant(string atout,int b)   //retourne l'indice du joueur gagant dans le le vecteur joueurs
{
    int index_Highest_Card ;
    //pour trouver l'indice du plus grande carte dans cardsontable
    for(int i=0;i<CardsOnTable.size();i++)
    {
        if(CardsOnTable[i]==compareTableCards(atout))
        {index_Highest_Card =i;}
    }
    //b : contient l'indice du joueur qui prend l'atout existe dans le main
    int res=(b+index_Highest_Card)%4;
    return res;
}

int Table:: somme_score(string at)   //retourne la somme des 4 cartes sur table 
{   int somme=0;
    for(int i=0;i<CardsOnTable.size();i++)
    {
        if(CardsOnTable[i].getCouleur()==at)
        {
            somme+=CardsOnTable[i].getVal_atout();
        }
        else
        {
            somme+=CardsOnTable[i].getVal_hors_atout();
        }
    }
    return somme;
}

void Table::Score(string atout,int b){
	 int score_pli;
	 if ((joueur_gagnant(atout,b)==0)||(joueur_gagnant(atout,b)==2))  //equipe 1 remporte le pli
    {
        score_pli=somme_score(atout);
		T1.setScore()=score_pli;
		
    }
    else      // equipe 2 remporte le pli
    {
        score_pli=somme_score(atout);
		T2.setScore()=score_pli;
		
    }
	
}
