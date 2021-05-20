//#include "boardgame.h"
#include "stdlib.h"
#include <QWidget>
#include "./include/Table.h"
#include <QLabel>
#include <QMouseEvent>
#include "clickableqlabel.h"
#include <QGridLayout>
#include <QPushButton>
#include <iostream>
#ifndef BOARDRELOAD_H
#define BOARDRELOAD_H


using namespace std;
class BoardReload
{
public:
    BoardReload(vector<Joueur>&,QWidget*);
//    void Rejouer(vector<Joueur>&,QWidget*);

private:
    QLabel* label;
    QLabel* label1;
};

#endif // BOARDRELOAD_H
