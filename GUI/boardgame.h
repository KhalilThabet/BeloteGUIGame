#ifndef BOARDGAME_H
#define BOARDGAME_H
#include "stdlib.h"
#include <QWidget>
#include "./include/Table.h"
#include <QLabel>
#include <QTimer>
#include <QVector>
#include <unistd.h>
#include <QMouseEvent>
#include "clickableqlabel.h"
#include <QGridLayout>
#include <QPushButton>
#include <QEventLoop>
#include <iostream>

using namespace std;
class BoardGame

{
public:
    BoardGame(vector<Joueur>&);

    //Methode qui affiche les cartes de chaque cote du terrain lors du tour du joueur desirer
    int ShowLeftCards(QGridLayout*,Table&);
    int ShowTopCards(QGridLayout*,Table&);
    int ShowRightCards(QGridLayout*,Table&);
    int ShowBotCards(QGridLayout*,Table&);

    //Methodes qui caches les cartes affichers dans les methodes precedentes
    void HideLeftCards();
    void HideTopCards();
    void HideRightCards();
    void HideBotCards();

    //Methode qui stockes les cartes et leurs images dans les attributs definits ci-dessouss
    void StoreTopCards(Table,QGridLayout*);
    void StoreBotCards(Table,QGridLayout*);
    void StoreRightCards(Table,QGridLayout*);
    void StoreLeftCards(Table,QGridLayout*);

    //Methodes qui deconnecte les widgets "ClickableLabel" se trouvant dans nos conteneurs creer dans les methodes Store####Cards
    void disconnectLeft();
    void disconnectRight();
    void disconnectTop();
    void disconnectBot();

    //Methode qui se charges des operation sur les cartes sur table et l'affichage du leaderBoard a la fin
    void run(Table&,QLabel*,QLabel*,int&);




private:

    QLabel* label; //Object pour le score de l'equipe 1
    QLabel* label1;//Object pour le score de l'equipe 1

    QLabel* Nom1;//Contient le nom du joueur1
    QLabel* Nom2;//Contient le nom du joueur2
    QLabel* Nom3;//Contient le nom du joueur3
    QLabel* Nom4;//Contient le nom du joueur4

    QVector<ClickableLabel*> TopHidden; //Conteneur d'images de cartes cacher du coter haut du jeu
    QVector<ClickableLabel*> TopDeck;   //Conteneur d'image de cartes nom cacher du coter haut du jeu
    QVector<ClickableLabel*> TopDeckFixe;   /*Conteneur qui sert a stocker les images des cartes dans le vecteur CardsOn Table
    afin d'eviter sa disparition lors de la surppression des cartes non voulu dans les conteneur plus haut*/
    QVector<Carte> TopCards;   //Conteneur des objects cartes

    QVector<ClickableLabel*> BotHidden; //Conteneur d'images de cartes cacher du coter haut du jeu
    QVector<ClickableLabel*> BotDeck; //Conteneur d'image de cartes nom cacher du coter bas du jeu
    QVector<ClickableLabel*> BotDeckFixe;/*Conteneur qui sert a stocker les images des cartes dans le vecteur CardsOnTable
    afin d'eviter sa disparition lors de la surppression des cartes non voulu dans les conteneur plus haut*/
    QVector<Carte> BotCards; //Conteneur des objects cartes

    QVector<ClickableLabel*> LeftHidden;//Conteneur d'images de cartes cacher du coter gauche du jeu
    QVector<ClickableLabel*> LeftDeck;//Conteneur d'image de cartes nom cacher du coter gauche du jeu
    QVector<ClickableLabel*> LeftDeckFixe;/*Conteneur qui sert a stocker les images des cartes dans le vecteur CardsOnTable
    afin d'eviter sa disparition lors de la surppression des cartes non voulu dans les conteneur du cote droit*/
    QVector<Carte> LeftCards; //Conteneur des objects cartes

    QVector<ClickableLabel*> RightHidden;//Conteneur d'images de cartes cacher du coter droit du jeu
    QVector<ClickableLabel*> RightDeck;//Conteneur d'image de cartes nom cacher du coter droit du jeu
    QVector<ClickableLabel*> RightDeckFixe;/*Conteneur qui sert a stocker les images des cartes dans le vecteur CardsOnTable
    afin d'eviter sa disparition lors de la surppression des cartes non voulu dans les conteneur du cote droit*/
    QVector<Carte> RightCards; //Conteneur des objects cartes

    QVector<ClickableLabel*> CardsOnTable; //Conteneur des cartes mises sur la table par les joueurs
     


};

#endif // BOARDGAME_H
