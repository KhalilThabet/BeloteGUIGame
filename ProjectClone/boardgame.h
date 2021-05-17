#ifndef BOARDGAME_H
#define BOARDGAME_H
#include "stdlib.h"
#include <QWidget>
#include "./include/Table.h"
#include <QLabel>
#include <QMouseEvent>
#include "clickableqlabel.h"
#include <QGridLayout>
#include <QPushButton>
#include <iostream>
//#include "./src/Functions.cpp"
//#include "./include/Joueur.h"
//#include "./include/Equipe.h"
using namespace std;
class BoardGame
{
public:
    BoardGame(vector<Joueur>&,QWidget*);

private:
    QLabel* label;
    QLabel* label1;

};

#endif // BOARDGAME_H
