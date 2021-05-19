#include "boardgame.h"
#include "./src/Functions.cpp"
#include "leaderboard.h"


BoardGame::BoardGame(vector<Joueur>& J,QWidget* BG)
{   

    QPushButton *Replay = new QPushButton("Rejouer");
    QPushButton *QuitButton = new QPushButton("Quit");
    QuitButton->setStyleSheet("background-color:white;");
    QGridLayout* layout=new QGridLayout;
    //initialising the grid size
    for(int i=0;i<14;i++){
        for(int j=0;j<15;j++){
        QLabel* l=new QLabel("");
        layout->addWidget(l,i,j);}
    }

    layout->addWidget(QuitButton,12,0,Qt::AlignBottom);
    BG->setStyleSheet("QWidget#BoardGame {background:url('C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/GroundImageBigger') no-repeat center center fixed ;background-size:cover;}");
    layout->addWidget(Replay,11,0,Qt::AlignBottom);
    QObject::connect(QuitButton,&QPushButton::clicked,BG,[BG](){delete BG;});
    //QObject::connect(Replay,&QPushButton::clicked,[s,BG](){BG->close();s(2);BG->show();});


    label=new QLabel("");
    label->setObjectName("Team2Score");
    label1=new QLabel("");
    label1->setObjectName("Team1Score");
    QString S;
    int a;a=rand() %4;
    cout<<"\n RandomValue a :"<<a<<endl;
    Joueur temp=J[a] ;
    J[a] = J[(a + 2) % 4];//operator=       //Echanger deux joueurs dans le vecteur Players_list aleatoirement
    J[(a + 2) % 4] = temp;                  //Juste un petit melange d'equipe
    Equipe T1(J[3], J[1]), T2(J[2],J[0]);   //Affectation des joueurs melanger dans le vecteur a des equipes

    Table T(J,T1,T2);                  //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
    int b;
    do{
        T.melange();
        distribute(T,5,21);            //distribue 5 cartes a chacun des joueurs
        b=retour_indice(T);            //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
    }while (b==-1);
    distribute(T,3,33,21,b);
    qDebug()<<"Cards Distributed !";

    QPushButton *btn=new QPushButton("here");
    layout->addWidget(btn,11,0);
////initialising deck's attributes
    affeectation_atout_joueur (T);


    StoreTopCards(T,layout); //Putting the cards of each player on the screen with each card a unique one
    StoreLeftCards(T,layout);
    StoreRightCards(T,layout);
    StoreBotCards(T,layout);


    label1->setText(QString::fromStdString(T.getT1().afficheTeam(1)+to_string(T.getT1().getScore())));
    label1->setStyleSheet("background:url(C:/Users/Khali/OneDrive/Bureau/Qt Training/Score.png) no-repeat;color:white;border-radius:5; padding:50 ;text-align:justify;font-family: 'Raleway',sans-serif; font-size: 18px; font-weight: 1000; line-height: 40px; text-align: center; text-transform: uppercase");
    layout->addWidget(label1,0,0,2,3);


    label->setText(QString::fromStdString(T.getT2().afficheTeam(2)+to_string(T.getT2().getScore())));
    label->setStyleSheet("background:url(C:/Users/Khali/OneDrive/Bureau/Qt Training/Score.png) no-repeat;color:white;border-radius:5; padding:50 ;text-align:justify;font-family: 'Raleway',sans-serif; font-size: 18px; font-weight: 1000; line-height: 40px; text-align: center; text-transform: uppercase");
    layout->addWidget(label,0,14,2,3);//,Qt::AlignRight

    // BotCards(layout);

            

    //vector<Carte> C=T.getJoueurs()[a].cartes_possible(T.getCardsOnTable(),(T.getAllCards()[20]).getCouleur());

    BG->setLayout(layout);
    BG->showFullScreen();

    //[this,layout](){LeftCards(layout);});
    int i=0;
    while(i<8){
        int j=0;
        int indexPlayer=(j+b)%4;
        qDebug()<<"INDEX OF PLAYER"<<indexPlayer;
        qDebug()<<"ATOUT"<<QString::fromStdString((T.getAllCards()[20]).getCouleur());
        if(indexPlayer==0){

            ShowLeftCards(layout,T);
            ShowBotCards(layout,T);
            ShowRightCards(layout,T);
            ShowTopCards(layout,T);
        }
        else if(indexPlayer==1){

            ShowBotCards(layout,T);
            ShowRightCards(layout,T);
            ShowTopCards(layout,T);
            ShowLeftCards(layout,T);
        }
        else if(indexPlayer==2){

            ShowRightCards(layout,T);
            ShowTopCards(layout,T);
            ShowLeftCards(layout,T);
            ShowBotCards(layout,T);
        }
        else{

            ShowTopCards(layout,T);
            ShowLeftCards(layout,T);
            ShowBotCards(layout,T);
            ShowRightCards(layout,T);
        }
        run(T,label1,label,b);

    i++;
    }
    //LeaderB LB(T);



}
 void BoardGame::run(Table& T,QLabel* label1,QLabel* label,int& b){

     string atout=(T.getAllCards()[20]).getCouleur();

     qDebug()<<QString::fromStdString(atout)<<"JG: "<<T.joueur_gagnant(atout,b);

     T.Score(atout,b);

     QTimer::singleShot(0,[label1,label,&T](){label1->setText(QString::fromStdString(T.getT1().afficheTeam(1)+to_string(T.getT1().getScore())));
                                        label->setText(QString::fromStdString(T.getT2().afficheTeam(2)+to_string(T.getT2().getScore())));
                                        qDebug()<<T.getT1().getScore();
                                        qDebug()<<T.getT2().getScore();});

     b=T.joueur_gagnant(atout,b);

     for(int i=0;i<CardsOnTable.size();i++){
         ClickableLabel* l=CardsOnTable[i];
         l->clear();
     }
     CardsOnTable={};
 }
 void BoardGame::StoreLeftCards(Table T,QGridLayout*layout){
     for(int i=3;i<11;i++){
                 Carte V=T.getJoueurs()[1].get_player_paquet().getPaquet()[i-3];
                 string stdString="<img src='"+V.getAddress90()+"'>";
                 QString s=QString::fromStdString(stdString);
                 string stdString1="<img src='"+V.getAddress0()+"'>";
                 QString s1=QString::fromStdString(stdString1);

                 ClickableLabel* HiddenRotated=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize90.png'>");
                 ClickableLabel* CardRotated=new ClickableLabel(s);
                 ClickableLabel* CardFixe=new ClickableLabel(s1);


                 LeftHidden.push_back(HiddenRotated);
                 LeftDeck.push_back(CardRotated);
                 LeftDeckFixe.push_back(CardFixe);
                 LeftCards.push_back(V);

                 layout->addWidget(HiddenRotated,i,0);

             }
 }
 int BoardGame::ShowLeftCards(QGridLayout* layout,Table& T){

     QEventLoop *loop=new QEventLoop;
     Nom1=new QLabel(QString::fromStdString(T.getJoueurs()[3].getNom()));
     Nom1->setStyleSheet("background:White;max-width:120;border-radius:200px;color: black;padding-left:10;padding-right:10; font-family: 'Raleway',sans-serif; font-size: 15px; font-weight: 700; line-height: 30px; text-align: center; text-transform: uppercase");
         for (int i=0;i<8;i++){
             ClickableLabel* l=LeftHidden[i];
             l->setVisible(false);
             ClickableLabel* l1=LeftDeck[i];
             l1->setVisible(true);
             ClickableLabel* l2=LeftDeckFixe[i];
             Carte V=LeftCards[i];

             layout->addWidget(l1,i+3,0);


             QObject::connect(l1,&ClickableLabel::clicked,[layout,l,l1,l2,V,loop,&T,this](){Nom1->hide();
                                                                                   disconnectLeft();
                                                                                   loop->quit();
                                                                                   CardsOnTable.push_back(l2);
                                                                                   layout->addWidget(l2,6,7);
                                                                                   l1->setText("");
                                                                                   l->setText("");
                                                                                   T.setCardsOnTable().push_back(V);
                                                                                   HideLeftCards();});//HideLeftCards(layout);

         }
         layout->addWidget(Nom1,6,2);


         loop->exec();

     return 0;
 }
 void BoardGame::disconnectLeft(){
     for(int i=0;i<8;i++){
         ClickableLabel* l=LeftDeck[i];
         l->disconnect();
     }
 }
 void BoardGame::HideLeftCards(){

     for (int i=0;i<8;i++){
         ClickableLabel* l=LeftHidden[i];
         ClickableLabel* l1=LeftDeck[i];
         l1->setVisible(false);
         l->setVisible(true);

     }

 }
 void BoardGame::StoreBotCards(Table T,QGridLayout* layout){
     for(int i=4;i<12;i++){
         Carte V=T.getJoueurs()[3].get_player_paquet().getPaquet()[i-4];
                 string stdString="<img src='"+V.getAddress0()+"'>";
                 QString s=QString::fromStdString(stdString);
                 ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
                 ClickableLabel* l1=new ClickableLabel(s);
                 ClickableLabel* l2=new ClickableLabel(s);

                 BotHidden.push_back(l);
                 BotDeck.push_back(l1);
                 BotDeckFixe.push_back(l2);
                 BotCards.push_back(V);
                 layout->addWidget(l,10,i,2,1);
             }
 }
 int BoardGame::ShowBotCards(QGridLayout* layout,Table& T){
     QEventLoop *loop=new QEventLoop;
     Nom2=new QLabel(QString::fromStdString(T.getJoueurs()[2].getNom()));
     Nom2->setStyleSheet("background:White;border:white;max-width:120;border-radius:200;color: black;padding-left:10;padding-right:10; font-family: 'Raleway',sans-serif; font-size: 15px; font-weight: 700; line-height: 30px; text-align: center; text-transform: uppercase");
     for(int i=0;i<8;i++){
         ClickableLabel* l=BotHidden[i];
         l->setVisible(false);
         ClickableLabel* l1=BotDeck[i];
         ClickableLabel* l2=BotDeckFixe[i];
         Carte V=BotCards[i];
         l1->setVisible(true);
         layout->addWidget(l1,10,i+4,2,1);
         QObject::connect(l1,&ClickableLabel::clicked,[layout,l,l1,l2,V,&T,loop,this](){Nom2->hide();
                                                                              disconnectBot();
                                                                               loop->quit();
                                                                               CardsOnTable.push_back(l2);
                                                                               layout->addWidget(l2,6,8);
                                                                               l->setText("");

                                                                               l1->setText("");
                                                                               T.setCardsOnTable().push_back(V);
                                                                               HideBotCards();});//HideBotCards(layout);

     }
     layout->addWidget(Nom2,9,7);
     loop->exec();
     return 0;
 }
 void BoardGame::disconnectBot(){
     for(int i=0;i<8;i++){
         ClickableLabel* l=BotDeck[i];
         l->disconnect();
     }
 }
 void BoardGame::HideBotCards(){
     for (int i=0;i<8;i++){
         ClickableLabel* l=BotHidden[i];
         ClickableLabel* l1=BotDeck[i];
         l->setVisible(true);
         l1->setVisible(false);

     }
 }
 void BoardGame::StoreTopCards(Table T,QGridLayout* layout){
     for(int i=4;i<12;i++){
         Carte V=T.getJoueurs()[2].get_player_paquet().getPaquet()[i-4];
                 string stdString="<img src='"+V.getAddress0()+"'>";
                 QString s=QString::fromStdString(stdString);
                 ClickableLabel* l=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize.png'>");
                 ClickableLabel* l1=new ClickableLabel(s);
                 ClickableLabel* l2=new ClickableLabel(s);

                 TopHidden.push_back(l);
                 TopDeck.push_back(l1);
                 TopDeckFixe.push_back(l2);
                 TopCards.push_back(V);
                 layout->addWidget(l,0,i,1,1);
             }
 }
 int BoardGame::ShowTopCards(QGridLayout* layout,Table& T){
     QEventLoop *loop=new QEventLoop;
     Nom3=new QLabel(QString::fromStdString(T.getJoueurs()[1].getNom()));
     Nom3->setStyleSheet("background:White;border:white;max-width:120;border-radius:200;color: black;padding-left:10;padding-right:10; font-family: 'Raleway',sans-serif; font-size: 15px; font-weight: 700; line-height: 30px; text-align: center; text-transform: uppercase");
     for(int i=0;i<8;i++){

         ClickableLabel* l=TopHidden[i];
         l->setVisible(false);
         ClickableLabel* l1=TopDeck[i];
         ClickableLabel* l2=TopDeckFixe[i];
         Carte V=TopCards[i];
         l1->setVisible(true);
         layout->addWidget(l1,0,i+4,1,1);
         QObject::connect(l1,&ClickableLabel::clicked,[layout,l,l1,l2,&T,V,loop,this](){Nom3->hide();
                                                                               disconnectTop(); //disconnect shown cards from clicking
                                                                               loop->quit();
                                                                               CardsOnTable.push_back(l2);
                                                                               layout->addWidget(l2,6,6);
                                                                               l->setText("");
                                                                               l1->setText("");
                                                                               T.setCardsOnTable().push_back(V);
                                                                               HideTopCards();});//HideTopCards(layout);LeftCards(layout);//emit l1->Screen();


     }
     layout->addWidget(Nom3,1,7);
     loop->exec();
     return 0;
 }
 void BoardGame::disconnectTop(){
     for(int i=0;i<8;i++){
         ClickableLabel* l1=TopDeck[i];
         l1->disconnect();
     }
 }
 void BoardGame::HideTopCards(){
     for (int i=0;i<8;i++){
         ClickableLabel* l=TopHidden[i];
         ClickableLabel* l1=TopDeck[i];
         l1->setVisible(false);
         l->setVisible(true);

     }
 }
 void BoardGame::StoreRightCards(Table T,QGridLayout* layout){
      for(int i=3;i<11;i++){
             Carte V=T.getJoueurs()[0].get_player_paquet().getPaquet()[i-3];
                 string stdString="<img src='"+V.getAddress90()+"'>";
                 QString s=QString::fromStdString(stdString);
                 string stdString1="<img src='"+V.getAddress0()+"'>";
                 QString s1=QString::fromStdString(stdString1);

                 ClickableLabel* HiddenRotated=new ClickableLabel("<img src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/CardlowerSize90.png'>");
                 ClickableLabel* CardRotated=new ClickableLabel(s);
                 ClickableLabel* CardFixe=new ClickableLabel(s1);

                 RightHidden.push_back(HiddenRotated);
                 RightDeck.push_back(CardRotated);
                 RightDeckFixe.push_back(CardFixe);
                 RightCards.push_back(V);
                 layout->addWidget(HiddenRotated,i,16);



             }
 }
 int BoardGame::ShowRightCards(QGridLayout* layout,Table& T){
     QEventLoop *loop=new QEventLoop;
     Nom4=new QLabel(QString::fromStdString(T.getJoueurs()[0].getNom()));
     Nom4->setStyleSheet("background:White;border:white;max-width:120;border-radius:200;color: black;padding-right:10;padding-left:10; font-family: 'Raleway',sans-serif; font-size: 15px; font-weight: 700; line-height: 30px; text-align: center; text-transform: uppercase");

     for(int i=0;i<8;i++){
             ClickableLabel* l=RightHidden[i];
             l->setVisible(false);
             ClickableLabel* l1=RightDeck[i];
             l1->setVisible(true);
             ClickableLabel*l2=RightDeckFixe[i];
             Carte V=RightCards[i];
             layout->addWidget(l1,i+3,16);
             QObject::connect(l1,&ClickableLabel::clicked,[layout,l,&T,V,l1,l2,loop,this](){Nom4->hide();
                                                                                   disconnectRight();
                                                                                   loop->quit();
                                                                                   CardsOnTable.push_back(l2);
                                                                                   layout->addWidget(l2,6,9);
                                                                                   l->setText("");
                                                                                   l1->setText("");
                                                                                   T.setCardsOnTable().push_back(V);
                                                                                   HideRightCards();});// HideRightCards(layout);
     }
     layout->addWidget(Nom4,7,15);
     loop->exec();
     return 0;

 }

 void BoardGame::disconnectRight(){
     for(int i=0;i<8;i++){
         ClickableLabel* l=RightHidden[i];
         l->disconnect();
     }
 }
 void BoardGame::HideRightCards(){
     for (int i=0;i<8;i++){
         ClickableLabel* l=RightHidden[i];
         ClickableLabel* l1=RightDeck[i];
         l->setVisible(true);
         l1->setVisible(false);


     }
 }
