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
    int ShowLeftCards(QGridLayout*);
    int ShowTopCards(QGridLayout*);
    int ShowRightCards(QGridLayout*);
    int ShowBotCards(QGridLayout*);

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
    void run(Table);



private:

    QLabel* label;
    QLabel* label1;

    QVector<ClickableLabel*> TopHidden;
    QVector<ClickableLabel*> TopDeck;
    QVector<ClickableLabel*> TopDeckFixe;

    QVector<ClickableLabel*> BotHidden;
    QVector<ClickableLabel*> BotDeck;
    QVector<ClickableLabel*> BotDeckFixe;

    QVector<ClickableLabel*> LeftHidden;
    QVector<ClickableLabel*> LeftDeck;
    QVector<ClickableLabel*> LeftDeckFixe;

    QVector<ClickableLabel*> RightHidden;
    QVector<ClickableLabel*> RightDeck;
    QVector<ClickableLabel*> RightDeckFixe;

    QVector<ClickableLabel*> CardsOnTable;
     


};

#endif // BOARDGAME_H
