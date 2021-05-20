#include "../include/Table.h"
#include <fstream>
Table::Table(vector<Joueur>& Players_list,Equipe& team1,Equipe& team2)
{	
	Equipe T1=team1;
	Equipe T2=team2;
	Joueurs = Players_list;
	
	ifstream sortie("C:/Users/ACHREF PC/Desktop/SchoolProject-Project/src/Belote.txt");		//Base de donne contenant les cartes du jeu
	if (sortie)
	{
		string s;
		int a;
		for (int i = 0;i < 32;i++)
		{
			Carte temp;					//Creation d'un objet temporaire Carte 
										//pour stocker les informations sortante
										//de la base de donnee
										
			sortie >> s;
			temp.setCouleur(s);
			sortie >> s; 
			temp.setValeur(s);
			sortie >> a;
			temp.setVal_atout(a);
			sortie >> a;
			temp.setVal_hors_atout(a);
			AllCards.push_back(temp);
		}
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier en lecture" << '\n';
	}
}


vector<Carte>& Table::getAllCards() {		//Accesseur Attribut AllCards
	return AllCards;
}
void Table::setAllCards(vector<Carte>& C) {		//Accesseur Attribut AllCards
	AllCards=C;
}
vector<Joueur>&  Table::getJoueurs() {			//Accesseur Attribut Joueurs
	return Joueurs;
}
void  Table::setJoueurs(vector<Joueur>& J) {			//Accesseur Attribut Joueurs
	Joueurs=J;
}


Equipe& Table::getT1()						//Accesseur Attribut T1
{
	return T1;
}
void Table::setT1(Equipe& T)
{
	T1=T;
}


Equipe& Table::getT2()						//Accesseur Attribut T2
{
	return T2;
}
void Table::setT2(Equipe& T)						//Accesseur Attribut T2
{
	T2=T;
}

void Table::melange()						//Melange des cartes du vecteur AllCards
{
	int b;
	for (int a = 0;a < 32;a++)
	{
		b = rand() % 32;
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
vector<Carte>& Table::getCardsOnTable(){
	return CardsOnTable;
}
void Table::setCardsOnTable(vector<Carte>& C){
	CardsOnTable=C;
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
		cout << "ajout de "<<score_pli<<" points\n";
        cout<<"les deux joueurs 0 et 2 gagnent cette manche  ";
		T1.changer_score(score_pli);
		
    }
    else      // equipe 2 remporte le pli
    {
        score_pli=somme_score(atout);
		cout << "ajout de "<<score_pli<<" points\n";
        cout<<"les deux joueurs 1 et 3 gagnent cette manche  ";
		T2.changer_score(score_pli);
		
    }
	
}