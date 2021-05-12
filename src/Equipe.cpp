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

int& Equipe::setatout()
{
    return atout;
}
void Equipe::afficheTeam(){
    cout<<"Affichage de l'equipe\n";
    for (int i=0;i<team.size();i++){
        cout<<team[i].getNom()<<" "<<team[i].getRang()<<"\n";
    }
}