#include "./include/Table.h"
#include "clickableqlabel.h"
#include <QPushButton>
#include <QGridLayout>
void UpperCards(QPushButton* btn,QGridLayout* layout,Table T){
    for(int i=4;i<12;i++){
        string stdString="<img src='"+T.getJoueurs()[2].get_player_paquet().getPaquet()[i-3].getAddress()+"'>";
        QString s=QString::fromStdString(stdString);
        ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
        //HiddenUpperDeck.push_back(l);
        layout->addWidget(l,0,i);
        ClickableLabel* l1=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize'>");
        ////////////////
            QObject::connect(l,&ClickableLabel::clicked,[layout,l,l1](){layout->addWidget(l1,7,6);l->setText("");emit l1->Screen();});
            QObject::connect(l1,&ClickableLabel::Screen,[l1,s](){l1->setText(s);});
    ///////////////////////
        QObject::connect(btn,&QPushButton::pressed,[l,s](){l->setText(s);});
        QObject::connect(btn,&QPushButton::released,[l](){l->setText("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize'>");});

    }

}
