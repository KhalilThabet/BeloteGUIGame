
#include "LaunchingGame.h"


void launchingGame::close(QWidget* w,vector<Joueur>& J){
    //Fonction qui sert de transition entre deux fenetre creer dans la fonction start
    qDebug()<<J.size();
    if (J.size()%4==0) {
        qDebug()<<QString::fromStdString(J[0].getNom());
        qDebug()<<QString::fromStdString(J[1].getNom());
        qDebug()<<QString::fromStdString(J[2].getNom());
        qDebug()<<QString::fromStdString(J[3].getNom());
        //Dans le cas ou le remplissage de noms termine , une operation de fermeture et de ouverture se lance
        QWidget* LoadingWindow=loading(); // Fenetre animation de chargement de l'application
        QTimer::singleShot(3000,[LoadingWindow](){LoadingWindow->close();});
        w->close();//fermeture de la fenetre de remplissage de noms
        BoardGame Je(J); //Creation d'une instance de la classe BoardGame qui lancera le jeu

    }
}
DynamicWidget* launchingGame::loading(){
    //Fonction qui sert a creer une fenetre animer de chargemet pour notre application
    DynamicWidget* LoadingScreen=new DynamicWidget("C:/Users/Khali/OneDrive/Bureau/Qt Training/loading.gif");
    LoadingScreen->showFullScreen(); // Affichage sur tout l'ecran
    LoadingScreen->setStyleSheet("background:black"); // Remplissage des espaces vide par la couleur noir
    return LoadingScreen;
}
int launchingGame::start()
{
    static vector<Joueur> Players_list={}; //Creation d'un vecteur de joueur qui servira a stocker les joueurs stockers

    QWidget *w=new QWidget; //Creation d'une nouvelle fenetre w comme window

    //Definition du style de l'arriere plan de la fenetre w
    w->setStyleSheet("background:url('C:/Users/Khali/OneDrive/Bureau/Qt Training/Login1.png') no-repeat center fixed;");

    QGridLayout* layout=new QGridLayout; //Creation d'un calque de travail

    for (int i = 0;i < 4;i++)
    {

          QLabel* label=new QLabel("Saisir le nom d'un joueur"+QString::number(i + 1)+":\n");
          QLineEdit* nom=new QLineEdit;

          //Definition des styles des deux objets creer precedemment
          nom->setPlaceholderText("Saisir votre Nom ici :");
          label->setStyleSheet("background:black;border-radius:50;padding:40 40 40 40;color: #ffffff; font-family: 'Raleway',sans-serif; font-size: 50px; font-weight: 700; line-height: 40px;margin-top:60;margin-bottom:60; text-align: center; text-transform: uppercase");
          nom->setStyleSheet("color:white;background-color:black;font-family: 'Raleway',sans-serif; font-size: 62px;height:60;width:300;border-radius:30;padding: 12px 20px;margin: 8px 0;border: none;border-bottom: 2px solid red;");

          //Ajout des widgets dans le calque de travail
          layout->addWidget(label,i,0,Qt::AlignCenter);
          layout->addWidget(nom,i,1,Qt::AlignCenter);


          //creation d'une connection entre les espaces des noms et une fonction lambda qui contient les operations desirees
          QObject::connect(nom,&QLineEdit::editingFinished,
                           [nom,i,w,label,this](){nom->hide(); //Cacher la widget de remplissage de nom pour la ligne i
                           label->setText("Received"); // Affectation du texte Received a la place de cette ligne
                           //Definition du style de ce texte
                           label->setStyleSheet("background:transparent;margin-left:500;color:green; font-family: 'Raleway',sans-serif; font-size: 62px; font-weight: 800; line-height: 72px; text-align: center; text-transform: uppercase");
                           Joueur J(nom->displayText().toLocal8Bit().constData(),i+1);//Creation d'un objet joueur et affectation du rang
                           Players_list.push_back(J);// Ajouter le joueur au conteneur static de joueur creer tout en haut de la fonction start
                           close(w,Players_list);}); //Appel a la fonction Close pour la transtion entre les fenetres


    }


    w->setLayout(layout);//Affection du calque de travail a la fentre
    w->showFullScreen(); // Affichage de la fentre en mode plein ecran

return 0;


}
