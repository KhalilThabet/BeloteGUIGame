#include "./src/Functions.cpp"
#include "boardreload.h"
//#include "./src/Functions.cpp"
//void BoardReload::Rejouer(vector<Joueur>& J,QWidget* BG){
//    //BoardGame B(J,BG);
//}

BoardReload::BoardReload(vector<Joueur>& J,QWidget* BG)
{
    QPushButton *Replay = new QPushButton("Rejouer");
    QPushButton *QuitButton = new QPushButton("Quit");
    QuitButton->setStyleSheet("background-color:white;");
    QGridLayout* layout=new QGridLayout;
    //initialising the grid size
    for(int i=0;i<14;i++){
        for(int j=0;j<15;j++){
        QLabel* l=new QLabel("");
//        if (j%2)l->setStyleSheet("background-color:red");
//        else l->setStyleSheet("background-color:blue");
        layout->addWidget(l,i,j);}
    }

    layout->addWidget(QuitButton,14,0,Qt::AlignBottom);
    BG->setStyleSheet("QWidget#BoardGame {background:url('C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/GroundImageBigger') no-repeat center center fixed ;background-size:cover;}");
    layout->addWidget(Replay,13,0,Qt::AlignBottom);
    QObject::connect(QuitButton,&QPushButton::clicked,BG,[BG](){BG->close();});
    QObject::connect(Replay,&QPushButton::clicked,[&](){BG->close();});


    label=new QLabel("");
    label->setObjectName("Team2Score");
    label->setStyleSheet("background:white;border-radius:5");
    label1=new QLabel("");
    label1->setObjectName("Team1Score");
    label1->setStyleSheet("background:white;border-radius:5");
    QString S;
    int a;a=rand() %4;
    cout<<"\n RandomValue a :"<<a<<endl;
    Joueur temp=J[a] ;
    J[a] = J[(a + 2) % 4];//operator=       //Echanger deux joueurs dans le vecteur Players_list aleatoirement
    J[(a + 2) % 4] = temp;                  //Juste un petit melange d'equipe
    for (int i=0;i<4;i++){
        cout<<J[i].getNom()<<" ";
    }
    Equipe T1(J[3], J[1]), T2(J[2],J[0]); //Affectation des joueurs melanger dans le vecteur a des equipes

    Table T(J,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
    int b;
    do{
        T.melange();
        distribute(T,5,21);            //distribue 5 cartes a chacun des joueurs
        b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
    }while (b==-1);
    distribute(T,3,33,21,b);
    qDebug()<<"Cards Distributed !";
    S=QString::fromStdString(T1.afficheTeam(1));
    label1->setText(S);
    layout->addWidget(label1,0,0,Qt::AlignLeft);

    S=QString::fromStdString(T2.afficheTeam(2));
    label->setText(S);
    layout->addWidget(label,0,14,Qt::AlignRight);
    QPushButton *btn=new QPushButton("here");
    layout->addWidget(btn,12,0);
////initialising deck's attributes


            for(int i=3;i<11;i++){

//qDebug()<<T.getJoueurs()[0].get_player_paquet().getPaquet().size();
                string stdString="<img src='"+T.getJoueurs()[1].get_player_paquet().getPaquet()[i-3].getAddress()+"'>";
                QString s=QString::fromStdString(stdString);
                ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize90'>");
//BoardGame::HiddenLeftDeck.push_back(l);
                layout->addWidget(l,i,0);
                ClickableLabel* l1=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize'>");
                QObject::connect(l,&ClickableLabel::clicked,[layout,l,l1](){layout->addWidget(l1,7,7);l->setText("");emit l1->Screen();});
                QObject::connect(l1,&ClickableLabel::Screen,[l1,s](){l1->setText(s);});

            }

            //qDebug()<<"<<<<<"<<BoardGame::HiddenLeftDeck.size();
        //    BeCarefull
        //    for(int i=3;i<11;i++){

        //        ClickableLabel* l=HiddenLeftDeck[i-3];
        //        layout->addWidget(l,i,0);

        //        QObject::connect(l,&ClickableLabel::clicked,[=](){RemoveCard(1);});

        //    }

            for(int i=4;i<12;i++){
                string stdString="<img src='"+T.getJoueurs()[2].get_player_paquet().getPaquet()[i-3].getAddress()+"'>";
                QString s=QString::fromStdString(stdString);
                ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
                //HiddenUpperDeck.push_back(l);
                layout->addWidget(l,0,i);
                ClickableLabel* l1=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize'>");
                QObject::connect(l,&ClickableLabel::clicked,[layout,l,l1](){layout->addWidget(l1,7,6);l->setText("");emit l1->Screen();});
                QObject::connect(l1,&ClickableLabel::Screen,[l1,s](){l1->setText(s);});
                QObject::connect(btn,&QPushButton::pressed,[l,s](){l->setText(s);});
                QObject::connect(btn,&QPushButton::released,[l](){l->setText("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize'>");});

            }
            for(int i=4;i<12;i++){
                string stdString="<img src='"+T.getJoueurs()[3].get_player_paquet().getPaquet()[i-3].getAddress()+"'>";
                QString s=QString::fromStdString(stdString);
                ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
                //HiddenLowerDeck.push_back(l);
                layout->addWidget(l,14,i);
                ClickableLabel* l1=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
                QObject::connect(l,&ClickableLabel::clicked,[layout,l,l1](){layout->addWidget(l1,7,8);l->setText("");emit l1->Screen();});
                QObject::connect(l1,&ClickableLabel::Screen,[l1,s](){l1->setText(s);});
            }

            for(int i=3;i<11;i++){

                string stdString="<img src='"+T.getJoueurs()[0].get_player_paquet().getPaquet()[i-3].getAddress()+"'>";
                QString s=QString::fromStdString(stdString);
                ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize90.png'>");
                //HiddenRightDeck.push_back(l);
                layout->addWidget(l,i,14);
                ClickableLabel* l1=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
                QObject::connect(l,&ClickableLabel::clicked,[layout,l,l1](){layout->addWidget(l1,7,9);l->setText("");emit l1->Screen();});
                QObject::connect(l1,&ClickableLabel::Screen,[l1,s](){l1->setText(s);});


            }

//    qDebug()<<HiddenLeftDeck.size();
//    for(int i=0;i<4;i++){
//        ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize'>");
//        layout->addWidget(l,7,6+i);
//        QObject::connect(l,&ClickableLabel::clicked,[l](){l->setText("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/lower/roi_coeur'>");});

//    }

    BG->setLayout(layout);
    BG->showFullScreen();

}

