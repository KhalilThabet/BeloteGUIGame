#include "../include/Carte.h"
Carte::Carte(){
    valeur = "Out";
	couleur = "Out";
    val_atout = -2;
    val_hors_atout =-2;
}
Carte::Carte(string Val, string Col,int Vatout,int VHatout)
{
	valeur = Val;
	couleur = Col;
    val_atout = Vatout;
    val_hors_atout =Vatout;
}
Carte::Carte(Carte* C){
    valeur = C->getValeur();
	couleur = C->getCouleur();
    val_atout = C->getVal_atout();
    val_hors_atout = C->getVal_hors_atout();

}

string& Carte::getCouleur()
{
	return couleur;
}


string& Carte::getValeur()
{
    return valeur;
}
void Carte::setCouleur(string& s)
{
	couleur=s;
}


void Carte::setValeur(string& s)
{
    valeur=s;
}

bool& Carte::getAtout(){
    return atout;
}
void Carte::setAtout(int a){
    atout=a;
}
	

int& Carte::getVal_atout(){
    return val_atout;
}
void Carte::setVal_atout(int& a){
    val_atout=a;
}
int& Carte::getVal_hors_atout(){
    return val_hors_atout;
}
void Carte::setVal_hors_atout(int& a){
    val_hors_atout=a;
}
int& Carte::getAcces(){
    return acces;
}
void Carte::setAcces(int& a){
    acces=a;
}

void Carte::operator=(Carte C){
    valeur = C.getValeur();
	couleur = C.getCouleur();
    atout=C.getAtout();
    acces=C.getAcces();
    val_atout = C.getVal_atout();
    val_hors_atout = C.getVal_hors_atout();

}
bool Carte::operator==(Carte Card){
    if (Card.getCouleur()==couleur && Card.getValeur()==valeur && Card.getAtout()==atout){
        return true;
    }
    return false;
}
int Carte:: compare (Carte obj,string atout) 
{

    
    if (couleur == atout){
        if(obj.getCouleur()==atout){
            int diff=val_atout-obj.getVal_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
        else if (obj.getCouleur() != atout){
            int diff=val_atout-obj.getVal_hors_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
    }
    else if (couleur != atout) {
        if (obj.getCouleur()==atout){
            int diff=val_hors_atout-obj.getVal_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
        else if (obj.getCouleur() != atout){
            int diff=val_hors_atout-obj.getVal_hors_atout();
            if (diff==0) return 0;
            else if (diff>0) return 1;
            else return -1;
        }
    }
    return -1;
}