#ifndef DYNAMICWIDGET_H
#define DYNAMICWIDGET_H


#include <QWidget>
#include <QMovie>

class DynamicWidget: public QWidget
{  //classe fille qui herite de QWidget et possede les meme proprietes sauf que l'arriere plan est dynamique
   Q_OBJECT
public:
   DynamicWidget(QString);
   virtual void paintEvent(QPaintEvent *event);
private:
   QMovie m_movie;
private slots:
   void paintNewFrame(int);
};
#endif // DYNAMICWIDGET_H
