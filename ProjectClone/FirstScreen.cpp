#include "main.cpp"
#include "boardgame.h"
#include "./include/Joueur.h"
#include "./src/joueur.cpp"
#include "./src/carte.cpp"
#include "./src/Table.cpp"
#include "./src/paquet_cartes.cpp"
#include "./src/Equipe.cpp"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include "unistd.h"
#include <QPushButton>
#include <QMovie>
#include <QTimer>
#include "test.h"
#include <QStyle>
#include <QApplication>
using namespace std;


int main(int argc, char *argv[])
{
    auto starter=loading; 
    auto board=start;

    static vector<Joueur> Players_list; //Un conteneur qui servira a stocker les joueurs et leurs nom pour le jeu

    QApplication app(argc, argv); //Debut de l'application

    TsTestWidget* test=new TsTestWidget("C:/Users/Khali/OneDrive/Bureau/Qt Training/Play.png"); //Creation d'une fenetre avec un arriere plan dynamique
    test->setStyleSheet("background:black;");//Fixation de la couleur de l'arriere plan au cas ou le media dynamique est de dimensions non parfaite a l'ecran


    QGridLayout* layout=new QGridLayout; // Creation d'une disposition en grid pour la fenetre

    QPushButton* Play=new QPushButton("PLAY");//Creation du button du commencement du jeu et definition de sa disposition
    Play->setStyleSheet("margin-left:200;margin-right:200;margin-bottom:30;height:100;background:white;border-radius:20");
    layout->addWidget(Play,1,2,Qt::AlignBottom);//ajout du bouton a la disposition
    
    TsTestWidget* x;
    QTimer *timer = new QTimer;//Creation d'un objet dynamique timer qui servira a ralentir le processus de transition entre les page et une animation d'un effet chargement de la page
    QObject::connect(Play,&QPushButton::clicked,[starter,test,&x,timer](){timer->start(3000);test->close();x=starter();}/*[&x,board](){}}*/);
    QObject::connect(timer, &QTimer::timeout,[board,&x,timer](){x->close();board();delete timer;});


    test->setLayout(layout);
    test->showFullScreen();




    app.exec();
    return 0;
 }
