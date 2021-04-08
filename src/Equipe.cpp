#include "Equipe.h"
#include "Joueur.h"

Equipe::Equipe(Joueur& J1,Joueur& J2)
{
    team.push_back(J1);
    team.push_back(J2);
}

Equipe::~Equipe()
{
    //dtor
}
int& Equipe::getScore() {
    return score;
}

void Equipe::setatout(int a =0)
{
    atout=a;
}


int& Equipe::getScore()
{
    return score;
}