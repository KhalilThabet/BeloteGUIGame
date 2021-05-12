#ifndef JOUEUR
#define JOUEUR
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Joueur{

    public:
    string name;
    int rank;
    Joueur(string s,int i){
        name=s;
        rank=i;
    }
    string getNom();
};

#endif
