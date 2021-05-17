#include "boardgame.h"
#include "./include/Joueur.h"
//#include "./src/joueur.cpp"
//#include "./src/carte.cpp"
//#include "./src/Table.cpp"
//#include "./src/paquet_cartes.cpp"
//#include "./src/Equipe.cpp"
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QTimer>
#include "unistd.h"
//#include <QPushButton>
#include "test.h"
//using namespace std;
//TsTestWidget* loading();
//class RunBoardGame{
//    vector<Joueur> Joueurs={};
//    QWidget* Window;
//public:
//    RunBoardGame(vector<Joueur>&J,QWidget* W){
//        Joueurs=J;
//        Window=W;
//    }
//    void operator()(){
//        BoardGame Je(Joueurs,Window);
//    }
//};

//void RunBoardGamr(vector<Joueur>& J,QWidget* NewWindow){
//    BoardGame Je(J,NewWindow);

//}
void close(QWidget* w,vector<Joueur>& J,QWidget* NewWindow){
    if (J.size()==4) {

        w->close();
        BoardGame Je(J,NewWindow);
//        TsTestWidget* x;
//        x=loading();
//        QTimer *timer = new QTimer;
//        QObject::connect(timer, &QTimer::timeout,[&x,timer,&R](){delete timer;x->close();R();});
//        timer->start(3000);

    }
}
TsTestWidget* loading(){
    TsTestWidget* LoadingScreen=new TsTestWidget("C:/Users/Khali/OneDrive/Bureau/Qt Training/loading1.gif");
    LoadingScreen->showFullScreen();
    LoadingScreen->setStyleSheet("background:black");
    return LoadingScreen;
}
int start()
{
    static vector<Joueur> Players_list;
//    QApplication app(argc, argv);
    QWidget *w=new QWidget;
    w->setObjectName("Menu");
    QWidget *BoardGame=new QWidget;
    BoardGame->setObjectName("BoardGame");
    w->setStyleSheet("background:url('C:/Users/Khali/OneDrive/Bureau/Qt Training/Login1.png') no-repeat center fixed;");

    string nom;
    QGridLayout* layout=new QGridLayout;

    for (int i = 0;i < 4;i++)
    {

          QLabel* label=new QLabel("Saisir le nom d'un joueur"+QString::number(i + 1)+":\n");
          QLineEdit* nom=new QLineEdit;
          nom->setPlaceholderText("Saisir votre Nom ici :");
          //label->setStyleSheet(" color: #111; font-family: 'Helvetica Neue', sans-serif; font-size: 20  px; font-weight: bold; letter-spacing: -1px; line-height: 1; text-align: center; ");
          label->setStyleSheet("background:black;border-radius:50;padding:40 40 40 40;color: #ffffff; font-family: 'Raleway',sans-serif; font-size: 50px; font-weight: 700; line-height: 40px;margin-top:60;margin-bottom:60; text-align: center; text-transform: uppercase");
          nom->setStyleSheet("color:white;background-color:black;font-family: 'Raleway',sans-serif; font-size: 62px;height:60;width:300;border-radius:30;padding: 12px 20px;margin: 8px 0;border: none;border-bottom: 2px solid red;");

          layout->addWidget(label,i,0,Qt::AlignCenter);
          layout->addWidget(nom,i,1,Qt::AlignCenter);
          QObject::connect(nom,&QLineEdit::editingFinished,
                           [nom,i,w,label,BoardGame](){nom->hide();
                           label->setText("Received");
                           label->setStyleSheet("background:transparent;margin-left:500;color:green; font-family: 'Raleway',sans-serif; font-size: 62px; font-weight: 800; line-height: 72px; text-align: center; text-transform: uppercase");
                           Joueur J(nom->displayText().toLocal8Bit().constData(),i+1);
                           Players_list.push_back(J);
                           close(w,Players_list,BoardGame);});//Affiche(Players_list);//.toLocal8Bit().constData()


    }


    w->setLayout(layout);
    w->showFullScreen();




////    while (1){
////        while (T1.getScore() < 200 && T2.getScore() < 200) {

////            Table T(Players_list,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
////            cout<<T.getAllCards().size();
////            int b;
////            int i=0;
////            do{
////                T.melange();
////                distribute(T,5,21);            //distribue 5 cartes a chacun des joueurs
////                b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
////            }while (b==-1);
////            distribute(T,3,33,21,b);
////            cout<<"********************\n";
////            for (int i=0;i<T.getJoueurs().size();i++){
////                display_cards(T.getJoueurs()[i].get_player_paquet().getPaquet());
////            }
////            for(int i=0;i<8;i++){
////                for(int j=3;j>=0;j--){
////                    vector<Carte> C=T.getJoueurs()[i].cartes_possible(T.getCardsOnTable(),"trefle");//Affiche les cartes possibles dans la main du joueur
////                    display_cards(C);
////                    T.getJoueurs()[i].sortir_carte(T.setCardsOnTable(),T.getJoueurs()[i].choisir_carte(C));
////                    //T.Score(); // Affecte les scores necessaires a chaque equipe(necessite de remplacer int& get score par un mutateur int& setScore)
////                    //necessite de creation d'un methode qui fait la comparaison entre les 4 cartes du vecteur CardsOnTable
////                }
////                display_cards(T.getCardsOnTable());
////            }
////        }

////        cout<<"Would you like to play another game?"<<endl;
////        string y;
////        cin>> y;
////        if (y=="No") break;
//    }
//    return 0;









////    return app.exec();
return 0;


}
