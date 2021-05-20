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

string Carte::getCouleur()
{
	return couleur;
}


string Carte::getValeur()
{
    return valeur;
}
string& Carte::setCouleur()
{
	return couleur;
}


string& Carte:: setValeur()
{
    return valeur;
}

bool Carte::getAtout(){
    return atout;
}
bool& Carte::setAtout(){
    return atout;
}
	

int Carte::getVal_atout(){
    return val_atout;
}
int& Carte::setVal_atout(){
    return val_atout;
}
int Carte::getVal_hors_atout(){
    return val_hors_atout;
}
int& Carte::setVal_hors_atout(){
    return val_hors_atout;
}
int Carte::getAcces(){
    return acces;
}
int& Carte::setAcces(){
    return acces;
}

string Carte::getAddress0(){
    return AddressVertical;
}
string& Carte::setAddress0(){
    return AddressVertical;
}
string Carte::getAddress90(){
    return AddressHorizontal;
}
string& Carte::setAddress90(){
    return AddressHorizontal;
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
{/* fonction qui fait la comparaison entre deux carte selon l'atout ou non atout
    retourne 0 s'ils sont egaux , 1 si la carte en main est superieur a celle sur la table
    sinon -1 si la carte sur table est superieur a la carte en main*/

    
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