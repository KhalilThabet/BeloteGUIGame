#include "../include/Equipe.h"

Equipe::Equipe(){
    team={};
}
Equipe::Equipe(Joueur& J1,Joueur& J2)
{
    team.push_back(J1);
    team.push_back(J2);
}

int Equipe::getScore() {
    return score;
}

void Equipe::setatout(int a)
{
    atout=a;
}
void Equipe::afficheTeam(){
    cout<<"Affichage de l'equipe\n";
    for (int i=0;i<team.size();i++){
        cout<<team[i].getNom()<<" "<<team[i].getRang()<<"\n";
    }
}
void Equipe::changer_score(int& val)
{
    score+=val;
    cout<<"Leurs score devient : " << score << " points \n " ;
}
void Equipe::afficher_score ()
{
    cout<<score<<endl;
}