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
//#include "./src/Functions.cpp"
//#include "./include/Joueur.h"
//#include "./include/Equipe.h"
using namespace std;
class BoardGame
{
public:
    BoardGame(vector<Joueur>&,QWidget*);
    int ShowLeftCards(QGridLayout*,Table&);
    int ShowTopCards(QGridLayout*,Table&);
    int ShowRightCards(QGridLayout*,Table&);
    int ShowBotCards(QGridLayout*,Table&);

    void HideLeftCards();
    void HideTopCards();
    void HideRightCards();
    void HideBotCards();

    void StoreTopCards(Table,QGridLayout*);
    void StoreBotCards(Table,QGridLayout*);
    void StoreRightCards(Table,QGridLayout*);
    void StoreLeftCards(Table,QGridLayout*);

    void disconnectLeft();
    void disconnectRight();
    void disconnectTop();
    void disconnectBot();


    // int getTopDeckSize();
    // int getLeftDeckSize();
    void run(Table&,QLabel*,QLabel*,int&);




private:

    QLabel* label;
    QLabel* label1;

    QLabel* Nom1;
    QLabel* Nom2;
    QLabel* Nom3;
    QLabel* Nom4;
    QVector<ClickableLabel*> TopHidden;
    QVector<ClickableLabel*> TopDeck;
    QVector<ClickableLabel*> TopDeckFixe;
    QVector<Carte> TopCards;

    QVector<ClickableLabel*> BotHidden;
    QVector<ClickableLabel*> BotDeck;
    QVector<ClickableLabel*> BotDeckFixe;
    QVector<Carte> BotCards;

    QVector<ClickableLabel*> LeftHidden;
    QVector<ClickableLabel*> LeftDeck;
    QVector<ClickableLabel*> LeftDeckFixe;
    QVector<Carte> LeftCards;

    QVector<ClickableLabel*> RightHidden;
    QVector<ClickableLabel*> RightDeck;
    QVector<ClickableLabel*> RightDeckFixe;
    QVector<Carte> RightCards;

    QVector<ClickableLabel*> CardsOnTable;
     


};

#endif // BOARDGAME_H
