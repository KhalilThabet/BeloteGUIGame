#include "leaderboard.h"
#include "FirstScreen.cpp"

LeaderB::LeaderB(Table T,QGridLayout* layout,QWidget* Window)
{


    launchingGame *LG=new launchingGame;                 //Creation d'une fenetre de relance pour le jeu

    int firstTeamScore=T.getT1().getScore();             //Score de la premier equipe
    int secondTeamScore=T.getT2().getScore();            //Score de la deuxieme equipe


    //Creation des objects de la fenetre
    QLabel* Score=new QLabel("");
    QPushButton* Rejouer=new QPushButton("REPLAY");
    QPushButton* Quit=new QPushButton("QUIT");

    //defition des styles de objects creer
    Score->setStyleSheet("color:white;margin-left:80;border-radius:100;text-align:justify;font-family: 'Raleway',sans-serif; font-size: 100px; font-weight: 1000; line-height: 40px; text-align: center; text-transform: uppercase");
    Rejouer->setStyleSheet("Background:white;margin-left:30;color:red;font-weight:900;height:60");
    Quit->setStyleSheet("Background:white;margin-left:30;color:red;font-weight:900;height:60");


    //Creation des connection entre Slots et signals creer par des objets
    QObject::connect(Quit,&QPushButton::clicked,[Window](){Window->close();});
    QObject::connect(Rejouer,&QPushButton::clicked,[Window,LG](){delete Window;LG->start();});


    //Verification du Score de l'equipe Gagnante
    if (firstTeamScore>secondTeamScore){
        Score->setText(QString::fromStdString("TEAM 1 WINS\n       "+std::to_string(firstTeamScore)));
    }
    else {
        Score->setText(QString::fromStdString("TEAM 2 WINS\n       "+std::to_string(secondTeamScore)));

    }

    //Ajout des widgets dans une grid de la fenetre actuelle
    layout->addWidget(Score,6,3);
    layout->addWidget(Rejouer,8,3);
    layout->addWidget(Quit,9,3);

    Window->setStyleSheet("Background:black");


}
