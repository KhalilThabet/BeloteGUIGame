#include "belote.h"
#include "ui_belote.h"
#include "joueur.h"
#include<QGridLayout>
belote::belote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::belote)
{
    ui->setupUi(this);
    setFixedSize(1300,680);
    outnomJ1=new QLabel(this);
    joueur J1;
    QGridLayout *layout =new QGridLayout;
    //QVector<QLabel*>::Iterator itr;
    //int i=0;
    for(int i=0;i<J1.getDosCarte().size();i++)
    {
        layout->addWidget((J1.getDosCarte())[i],0,i);

    }
    this->setLayout(layout);


}
void belote::recvText(const QString &text){

    QString input = text;
    //outnomJ1->clear();
    outnomJ1->setText(input);
   // outnomJ1->update();

}

belote::~belote()
{
    delete ui;
}
