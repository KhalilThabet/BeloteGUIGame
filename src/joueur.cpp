#include "../include/Joueur.h"
Joueur::Joueur(){}

Joueur::Joueur(string name,int Rg)
{
	Nom=name;
	Rang=Rg;
}

string Joueur:: getNom()const
{
    return Nom;
}


int Joueur:: getRang()const
{
    return Rang;
}
int& Joueur::setRang()
{
	return Rang;
}

Paquet_cartes Joueur:: get_player_paquet()const
{
	return Paquet;
}
Paquet_cartes& Joueur:: set_player_paquet()
{
	return Paquet;
}

void Joueur::operator=(Joueur cop)
{
    Nom = cop.getNom();
    Rang = cop.getRang();
    Paquet = cop.get_player_paquet();}
// int main(){
// 	Joueur J("Aziz",1);
// 	Joueur J1("Khalil",2);
// 	Joueur J2("Mohamed",3);
// 	cout<<"Testing Joueur.cpp"<<endl;
// 	cout<<"Nom des joueurs : "<<J.getNom()<<" "<<J1.getNom()<<" "<<J2.getNom()<<endl;
// 	J2=J1;
// 	cout<<"Changement en cours"<<endl;
// 	cout<<"Nom des joueurs : "<<J.getNom()<<" "<<J1.getNom()<<" "<<J2.getNom()<<endl;}

vector<Carte> Joueur::cartes_possible(Table& T,string atout)
{	
	vector<Carte> cartes;
    if (T.getCardsOnTable().size()==0){
        return Paquet.getPaquet();
    }
    else{
        for(int i=0;i<Paquet.getPaquet().size();i++)
        {
            if (Paquet.getPaquet()[i].getCouleur()==T.getCardsOnTable()[0].getCouleur() || Paquet.getPaquet()[i].getCouleur()==atout){
                cartes.push_back(Paquet.getPaquet()[i]);
            }
        }
        if (cartes.size()==0){
            return Paquet.getPaquet();
        }
        return cartes;
        
    }
	
}


void Joueur::sortir_carte(vector<Carte>& CardsOnTable,Carte ChosenCard)
{
    vector<Carte> Temp=this->set_player_paquet().setPaquet();
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
