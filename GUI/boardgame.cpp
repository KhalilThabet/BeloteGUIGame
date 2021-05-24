#include "boardgame.h"
#include "./src/Functions.cpp"
#include <ctime>
#include "leaderboard.h"


BoardGame::BoardGame(vector<Joueur>& J)
{   
    QWidget* BG=new QWidget;

    QPushButton *QuitButton = new QPushButton("Quit"); //Creation d'un bouton Quitter pour le joueur desirer de quitter le jeu a tout moment
    QuitButton->setStyleSheet("background-color:white;");//Definition dy style du bouton
    QPushButton *Replay = new QPushButton("Replay");
    QGridLayout* layout=new QGridLayout; //Creation d'un calque grid

    BG->setObjectName("BoardGame");//Defition du nom de l'object de la fentre BG

    //initialisation de la grid par des valeurs vides

    for(int i=0;i<14;i++){
        for(int j=0;j<15;j++){
        QLabel* l=new QLabel("");
        layout->addWidget(l,i,j);}
    }

    layout->addWidget(QuitButton,12,0,Qt::AlignBottom); //Ajout du bouton quitter a une position donner
    BG->setStyleSheet("QWidget#BoardGame {background:url('C:/Users/Khali/OneDrive/Bureau/SchoolProject/cartes/GroundImageBigger') no-repeat center center fixed ;background-size:cover;}");
    layout->addWidget(Replay,13,0,Qt::AlignBottom);
    QObject::connect(QuitButton,&QPushButton::clicked,BG,[BG](){delete BG;});//Creation d'une connection avec le bouton et la femeture de la fentre

    label=new QLabel("");
    label1=new QLabel("");

    int a=time(0)%4;
    cout<<"\n RandomValue a :"<<a<<endl;
    Joueur temp=J[a] ;
    J[a] = J[(a + 2) % 4];//operator=       //Echanger deux joueurs dans le vecteur Players_list aleatoirement
    J[(a + 2) % 4] = temp;                  //Juste un petit melange d'equipe
    Equipe T1(J[3], J[1]), T2(J[2],J[0]);   //Affectation des joueurs melanger dans le vecteur a des equipes

    Table T(J,T1,T2);                  //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
    static int b;
    int j=1;

    do{
        T.melange();                    //Melange des 32 cartes se trouvant dans AllCards
        distribute(T,5,21);             //distribue 5 cartes a chacun des joueurs
        b=retour_indice(T,layout,j);      //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
    }while (b==-1);
    distribute(T,3,33,21,b);

    affeectation_atout_joueur (T);

////initialising deck's attributes
    //Putting the cards of each player on the screen with each card a unique one
    StoreTopCards(T,layout);
    StoreLeftCards(T,layout);
    StoreRightCards(T,layout);
    StoreBotCards(T,layout);


    label1->setText(QString::fromStdString(T.getT1().afficheTeam(1)+to_string(T.getT1().getScore())));
    label1->setStyleSheet("background:url(C:/Users/Khali/OneDrive/Bureau/Qt Training/Score.png) no-repeat;color:white;border-radius:5; padding:50 ;text-align:justify;font-family: 'Raleway',sans-serif; font-size: 18px; font-weight: 1000; line-height: 40px; text-align: center; text-transform: uppercase");
    layout->addWidget(label1,0,0,2,3);//Ajout de la widget des scores de la seconde equipe au calque de travail


    label->setText(QString::fromStdString(T.getT2().afficheTeam(2)+to_string(T.getT2().getScore())));
    label->setStyleSheet("background:url(C:/Users/Khali/OneDrive/Bureau/Qt Training/Score.png) no-repeat;color:white;border-radius:5; padding:50 ;text-align:justify;font-family: 'Raleway',sans-serif; font-size: 18px; font-weight: 1000; line-height: 40px; text-align: center; text-transform: uppercase");
    layout->addWidget(label,0,14,2,3);//Ajout de la widget des score de la premiere equipe a la grid de travail


    QObject::connect(Replay,&QPushButton::clicked,[layout,&T,BG](){LeaderB B(T,layout,BG);});


    //vector<Carte> C=T.getJoueurs()[a].cartes_possible(T.getCardsOnTable(),(T.getAllCards()[20]).getCouleur());

    BG->setLayout(layout);
    BG->showFullScreen();
    auto verif=verify;
    for (int i=0;i<4;i++){
        int k=-1;
    QEventLoop* loop=new QEventLoop;

            qDebug()<<"Entering Loop";
            QLabel* label=new QLabel(QString::fromStdString((T.getAllCards()[20]).getValeur()+" "+(T.getAllCards()[20]).getCouleur())) ;
            QLineEdit* Response=new QLineEdit;
            Response->setPlaceholderText("Yes/No");
            layout->addWidget(label,3,6);
            layout->addWidget(Response,4,6);
            QObject::connect(Response,&QLineEdit::editingFinished,[Response,label,loop,&k,&i,&j,verif](){Response->close();label->close();loop->exit();j=verif(Response->displayText().toLocal8Bit().constData(),i,k);});

    loop->exec();
    if (k>0) i=4;
}
    int i=0;
    while(i<8){ //Boucle pour les 8 pli qui doivent etre jouer
        int j=0;
        int indexPlayer=(j+b)%4;//Indice du premier joueur a jouer dans le pli

        //Definition des tours de chaque joueur
        if(indexPlayer==0){

            ShowLeftCards(layout,T);j++;
            ShowBotCards(layout,T);
            ShowRightCards(layout,T);
            ShowTopCards(layout,T);
        }
        else if(indexPlayer==1){

            ShowBotCards(layout,T);j++;
            ShowRightCards(layout,T);
            ShowTopCards(layout,T);
            ShowLeftCards(layout,T);
        }
        else if(indexPlayer==2){

            ShowRightCards(layout,T);j++;
            ShowTopCards(layout,T);
            ShowLeftCards(layout,T);
            ShowBotCards(layout,T);
        }
        else{

            ShowTopCards(layout,T);j++;
            ShowLeftCards(layout,T);
            ShowBotCards(layout,T);
            ShowRightCards(layout,T);
        }
        run(T,label1,label,b);

    i++;
    }
    //Relance de l'application a partir de la fenetre de remplissage de nom



}
 void BoardGame::run(Table& T,QLabel* label1,QLabel* label,int& b){

     string atout=(T.getAllCards()[20]).getCouleur();//Variable qui sert a stocker l'atout du jeu de la 21 cartes distribuer


     T.Score(atout,b);//Calcule et affectation des scores a travers les cartes mises sur table

     QTimer::singleShot(0,[label1,label,&T](){label1->setText(QString::fromStdString(T.getT1().afficheTeam(1)+to_string(T.getT1().getScore())));
                                        label->setText(QString::fromStdString(T.getT2().afficheTeam(2)+to_string(T.getT2().getScore())));
                                        qDebug()<<T.getT1().getScore();//Verification du score de la premiere equipe dans la console
                                        qDebug()<<T.getT2().getScore();}); //Verification du score de la seconde equipe dans la console});

     b=T.joueur_gagnant(atout,b);//Reaffection de l'indice du joueur gagnant dans le pli precedent

     for(int i=0;i<CardsOnTable.size();i++){
         ClickableLabel* l=CardsOnTable[i];
         l->clear();//Effacant les cartes mises la table
     }
     CardsOnTable={}; //Vider le conteneur
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
