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
using namespace std;
#include "test.h"
#include <QStyle>
#include <QApplication>

int main(int argc, char *argv[])
{
    auto starter=loading;
    auto board=start;
    static vector<Joueur> Players_list;
    QApplication app(argc, argv);
    TsTestWidget* test=new TsTestWidget("C:/Users/Khali/OneDrive/Bureau/Qt Training/Play.png");
    test->setFixedSize(1100,800);
    test->setStyleSheet("background:black;");


    QGridLayout* layout=new QGridLayout;
    QPushButton* Play=new QPushButton("PLAY");
    Play->setStyleSheet("margin-left:200;margin-right:200;margin-bottom:30;height:100;background:white;border-radius:20");
    layout->addWidget(Play,1,2,Qt::AlignBottom);
    TsTestWidget* x;
    QTimer *timer = new QTimer;
    QObject::connect(Play,&QPushButton::clicked,[starter,test,&x,timer](){timer->start(3000);test->close();x=starter();}/*[&x,board](){}}*/);
    QObject::connect(timer, &QTimer::timeout,[board,&x,timer](){x->close();board();delete timer;});


    test->setLayout(layout);
    test->showFullScreen();



//    w->setLayout(layout);
//    w->show();
    app.exec();
    return 0;
 }
