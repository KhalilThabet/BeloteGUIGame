#include "Joueur.h"
#include <iostream>
#include "Paquet_cartes.h"

Joueur::Joueur(string name,int c)
{
	Nom=name;
	Rang=c;
}

string Joueur:: getNom()
{
    return Nom;
}


int& Joueur:: getRang()
{
    return Rang;
}

Paquet_cartes& Joueur:: get_player_paquet()
{
	return Paquet;
}



/*bool Joueur:: Couleur_exist_EnMain(Couleur couleur){}

virtual Carte sortir_Carte(Carte carte_avant, Couleur atout){}

vector<Carte> Joueur:: cartes_possible(Carte carte_avant,Couleur atout){}*/












/*
vector<Carte> Joueur::cartes_possible(Carte carte_avant,Couleur atout)
{
	std::vector<Carte> cartes_poss;
	if(carte_avant.getValeur()==0)
		cartesordi = m_main;
	else
	{
	Carte cartePremier = avantCarte[0];
	if(cartePremier.getCouleur()==atout)
		{
			int flag1 = 0;
			for(int i = 0;i<m_main.size();i++)
			{
				Carte carte = m_main[i];
				int flag2 = 1;
				for(int j = 0;j<avantCarte.size();j++)
				{
					Carte carteavant = avantCarte[j];
					if(!carte.isSuperieur(carteavant,atout,atout))
					{
						flag2 = 0;
						break;
					}
				}
				if(flag2==1)
				{
					cartesordi.push_back(carte);
					flag1=1;
				}

			}
			if(flag1==0)
			{
				cartesordi = m_main;
			}
		}

		else if(cartePremier.getCouleur()!=atout)
		{
			int flag1 = 0;
			for(int i = 0;i<m_main.size();i++)
			{
				Carte carte = m_main[i];
				if(carte.getCouleur()==cartePremier.getCouleur())
				{
					cartesordi.push_back(carte);
					flag1 = 1;
				}
			}
			if(flag1==0)
			{
				cartesordi=m_main;
			}
		}
	}
	return cartesordi;
}

*/