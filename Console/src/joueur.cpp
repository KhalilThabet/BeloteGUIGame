#include "../include/Joueur.h"

Joueur::Joueur(){}

Joueur::Joueur(string name,int Rg)
{
	Nom=name;
	Rang=Rg;
}

string& Joueur:: getNom()
{
    return Nom;
}


int& Joueur:: getRang()
{
    return Rang;
}
void Joueur::setRang(int& a)
{
	Rang=a;
}

vector<Carte>& Joueur:: get_player_paquet()
{
	return Paquet;
}
void Joueur:: set_player_paquet(vector<Carte>& P)
{
	Paquet.insert(Paquet.end(),P.begin(),P.end());
}

void Joueur::operator=(Joueur cop)
{
    Nom = cop.getNom();
    Rang = cop.getRang();
    Paquet = cop.get_player_paquet();
}
vector<Carte> Joueur::cartes_possible(vector<Carte> CardsOnTable,string atout)
{	
    int a=0;
	vector<Carte> cartes;
    if (CardsOnTable.size()==0){
        return Paquet;
    }
    else{
        for(int i=0;i<Paquet.size();i++)
        {
            if (Paquet[i].getCouleur()==CardsOnTable[0].getCouleur())
            {
                cartes.push_back(Paquet[i]);
                a+=1;
            }
            else {
            if ((Paquet[i].getCouleur()==atout) && (a=0))
            {
                cartes.push_back(Paquet[i]);
            }
            }
        }
        if (cartes.size()==0){
            return Paquet;
        }
        return cartes;
        
    }
	
}

Carte Joueur::choisir_carte(vector<Carte>& cartes_possible){
    cout<<"Choisir un numero entre 1 et "<<cartes_possible.size()<<endl;
    int i;cin>>i;
    return cartes_possible[i-1];
}

void Joueur::sortir_carte(vector<Carte>& CardsOnTable,Carte ChosenCard)
{
    vector<Carte>& Temp=Paquet;
    vector<Carte>::iterator itr,storePosition;
    for(itr=Temp.begin();itr!=Temp.end();itr++){
        if ((*itr)==ChosenCard){
            storePosition=itr;
            break;
        }
    }
    Temp.erase(storePosition);
	CardsOnTable.push_back(ChosenCard);
}
