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
using namespace std;


#include <QApplication>
//void Affiche(vector<Joueur>& J){
//    if (4==Players_list.size())
//    {   for(int i=0;i<4;i++){
//              qDebug()<<QString::fromStdString(Players_list[i].getNom());
//          }
//    }
//    if (J.size()==4){
//    for(int i=0;i<4;i++)qDebug()<<QString::fromStdString(J[i].getNom());}
//}
void close(QWidget* w,vector<Joueur>& J,QWidget* NewWindow){
    if (J.size()==4) {
//        sleep(1);
        w->close();
//        QApplication::exit(1000);

        BoardGame B(J,NewWindow);
    }
}
int main(int argc, char *argv[])
{

    int currentExitCode = 0;
do {
    static vector<Joueur> Players_list;
    QApplication app(argc, argv);
    QWidget *w=new QWidget;
    w->setObjectName("Menu");
    QWidget *BoardGame=new QWidget;
    BoardGame->setObjectName("BoardGame");

    string nom;
    QGridLayout* layout=new QGridLayout;
    //QString *s=new QString("");
    for (int i = 0;i < 4;i++)
    {

          QLabel* label=new QLabel("Saisir le nom d'un joueur"+QString::number(i + 1)+":\n");
          QLineEdit* nom=new QLineEdit;
          nom->setPlaceholderText("Saisir votre Nom ici :");
          layout->addWidget(label,i,0,Qt::AlignCenter);
          layout->addWidget(nom,i,1,Qt::AlignCenter);
          QObject::connect(nom,&QLineEdit::editingFinished,
                           [nom,i,w,label,BoardGame](){nom->hide();
                           label->setText("Received");
                           Joueur J(nom->displayText().toLocal8Bit().constData(),i+1);
                           Players_list.push_back(J);
                           close(w,Players_list,BoardGame);});//Affiche(Players_list);//.toLocal8Bit().constData()


    }


    w->setLayout(layout);
    w->show();




//    while (1){
//        while (T1.getScore() < 200 && T2.getScore() < 200) {

//            Table T(Players_list,T1,T2);    //Creation d'un objet table qui fera de reference entre toutes les classes duant le jeu
//            cout<<T.getAllCards().size();
//            int b;
//            int i=0;
//            do{
//                T.melange();
//                distribute(T,5,21);            //distribue 5 cartes a chacun des joueurs
//                b=retour_indice(T);         //Proposer une carte sur table pour tous les joueurs et retourne lindice de celui qui la saisie
//            }while (b==-1);
//            distribute(T,3,33,21,b);
//            cout<<"********************\n";
//            for (int i=0;i<T.getJoueurs().size();i++){
//                display_cards(T.getJoueurs()[i].get_player_paquet().getPaquet());
//            }
//            for(int i=0;i<8;i++){
//                for(int j=3;j>=0;j--){
//                    vector<Carte> C=T.getJoueurs()[i].cartes_possible(T.getCardsOnTable(),"trefle");//Affiche les cartes possibles dans la main du joueur
//                    display_cards(C);
//                    T.getJoueurs()[i].sortir_carte(T.setCardsOnTable(),T.getJoueurs()[i].choisir_carte(C));
//                    //T.Score(); // Affecte les scores necessaires a chaque equipe(necessite de remplacer int& get score par un mutateur int& setScore)
//                    //necessite de creation d'un methode qui fait la comparaison entre les 4 cartes du vecteur CardsOnTable
//                }
//                display_cards(T.getCardsOnTable());
//            }
//        }

//        cout<<"Would you like to play another game?"<<endl;
//        string y;
//        cin>> y;
//        if (y=="No") break;
//    }
//    return 0;









    currentExitCode=app.exec();
    } while( currentExitCode == 1000 );
    return currentExitCode;


}