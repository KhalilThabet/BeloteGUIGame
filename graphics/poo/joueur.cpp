#include "joueur.h"

joueur::joueur()
{
  for(int i=0;i<8;i++)
  {
      QLabel *label=new QLabel;
      QPixmap pixmap("C:/Users/Ammari Ala/Desktop/image/BlueCardBack.png");
      label->setPixmap(pixmap);
      label->setMask(pixmap.mask());
      label->setStyleSheet("margin: 10%");
      //label->show();
      dosdecartes.push_back(label);

  }
}
QVector<QLabel*>& joueur:: getDosCarte()
{
    return dosdecartes;
}
