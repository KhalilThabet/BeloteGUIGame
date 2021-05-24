#ifndef LAUNCHINGGAME_H
#define LAUNCHINGGAME_H
#include "boardgame.h"
#include "./include/Joueur.h"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTimer>
#include "unistd.h"
#include "DynamicWidget.h"
class launchingGame{
    friend class BoardGame;
public:
    launchingGame(){};
    void close(QWidget*,vector<Joueur>&);
    DynamicWidget* loading();
    int start();


};

#endif // LAUNCHINGGAME_H
