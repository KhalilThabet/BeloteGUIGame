#include "leaderboard.h"
#include "test.h"
LeaderB::LeaderB(Table T)
{
    //TsTestWidget *BoardWindow=new TsTestWidget("C:/Users/Khali/OneDrive/Bureau/Qt Training/image.jpg");
    QWidget *BoardWindow=new QWidget;
    int firstTeamScore=T.getT1().getScore();
    int secondTeamScore=T.getT2().getScore();
    QLabel* Score=new QLabel("");
    QLabel* Nom1=new QLabel("");
    QLabel* Nom2=new QLabel("");
    QGridLayout* layout=new QGridLayout;

    if (firstTeamScore>secondTeamScore){
        Score->setText(QString::fromStdString(to_string(firstTeamScore)));
        Nom1->setText(QString::fromStdString((T.getT1().getTeam()[0]).getNom()));
        Nom2->setText(QString::fromStdString((T.getT1().getTeam()[1]).getNom()));
    }
    else {
        Score->setText(QString::fromStdString(to_string(secondTeamScore)));
        Nom1->setText(QString::fromStdString((T.getT2().getTeam()[0]).getNom()));
        Nom2->setText(QString::fromStdString((T.getT2().getTeam()[1]).getNom()));
    }
    layout->addWidget(Score,0,0);
    layout->addWidget(Nom1,1,0);
    layout->addWidget(Nom2,2,0);
    BoardWindow->setLayout(layout);
    BoardWindow->show();

}
