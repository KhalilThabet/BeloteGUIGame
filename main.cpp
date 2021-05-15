#include "window.h"
#include <QLabel>
#include <QGridLayout>
#include <QWidget>
#include <QFrame>
#include <QScrollBar>
QGridLayout* VerticalCards(int j,int k,QGridLayout* MainLayout){
    QVector<QLabel*> Vlabel;
    for (int i=0;i<10;i++) {
        if (i==0 || i==9) Vlabel.push_back(new QLabel(""));
        else Vlabel.push_back(new QLabel("<img style='max-height:30px;max-width:20px;width:20px;' src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/CardlowerSize90'>"));
    }
    for (int i=j;i<j+10;i++){
        QVBoxLayout *layout=new QVBoxLayout;
        QLabel *temp=Vlabel[i];
        if (i==j+9 || i==j){
        temp->setMargin(100);}
        temp->setScaledContents(true);
        layout->addSpacing(-50);
        layout->setSizeConstraint(QLayout::SetFixedSize);
        layout->addWidget(temp);


        MainLayout->addLayout(layout,i,k);
        MainLayout->addLayout(layout,i,k);
    }
    return MainLayout;
}
QGridLayout* HorizontalCards(int j,int k,QGridLayout* MainLayout){
    QVector<QLabel*> Vlabel;
    for (int i=0;i<10;i++) {
        if (i==0 || i==9) Vlabel.push_back(new QLabel(""));
        else Vlabel.push_back(new QLabel("<img style='max-height:30px;max-width:20px;width:20px;' src='C:/Users/Khali/OneDrive/Bureau/SchoolProject/CardlowerSize'>"));
    }
    for (int i=j;i<j+10;i++){
        QHBoxLayout *layout=new QHBoxLayout;
        QLabel *temp=Vlabel[i];
        if (i==j+9 || i==j){
        temp->setMargin(200);}
        temp->setScaledContents(true);
        layout->addSpacing(-20);
        layout->setSizeConstraint(QLayout::SetFixedSize);
        layout->addWidget(temp);


        MainLayout->addLayout(layout,k,i);
        MainLayout->addLayout(layout,k,i);
    }
    return MainLayout;
}
int main(int argc, char *argv[])
{
    QApplication App(argc,argv);
    Window win;
    QGridLayout *MainLayout=new QGridLayout;
    win.setStyleSheet("QWidget#label {text-shadow:;display:box; background: #141414; padding: 30px;color:#fff;background-color:#2E8ECE;} #Window {background-color:green} #button{position: absolute;top: 50%;left: 50%;transform: translate(-50%, -50%);-ms-transform: translate(-50%, -50%);background-color: #f1f1f1;color: black;font-size: 16px;padding: 16px 30px;border: none;cursor: pointer;border-radius: 5px;text-align: center;} #button:hover{background-color: black;color: white;}");
//    for (int i=0;i<8;i++){
//        QHBoxLayout *layout=new QHBoxLayout;
//        QLabel *temp=Vlabel[i];
//        temp->setScaledContents(true);
//        //temp->height();temp->width();
//        layout->addSpacing(-20);
//        layout->setSizeConstraint(QLayout::SetFixedSize);
//        layout->addWidget(temp);
//        MainLayout->addLayout(layout,1,i);
//    }
    MainLayout->addLayout(HorizontalCards(0,0,MainLayout),0,4);
    MainLayout->addLayout(VerticalCards(0,0,MainLayout),4,0);
    MainLayout->addLayout(HorizontalCards(0,20,MainLayout),4,4);
    MainLayout->addLayout(VerticalCards(0,20,MainLayout),4,4);

//    layout->setContentsMargins(100,200,100,200);
//    layout->addWidget(win.Img(),0,1);
//    layout->addWidget(win.labl(),1,1);
//    layout->addWidget(win.labl1(),2,1);
//    layout->addWidget(win.text(),3,1);
//    layout->addWidget(win.btn(),4,1);
//    MainLayout->addWidget(Scroll);
    win.setLayout(MainLayout);
    win.show();
    //w.show();









    return App.exec();
}
