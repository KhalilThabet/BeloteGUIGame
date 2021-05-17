#ifndef TEST_H
#define TEST_H


#include <QWidget>
#include <QMovie>

class TsTestWidget: public QWidget
{
   Q_OBJECT
public:
   TsTestWidget(QString);
   virtual void paintEvent(QPaintEvent *event);
private:
   QMovie m_movie;
private slots:
   void paintNewFrame(int);
};
#endif // TEST_H
