#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <string>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QVector>

class Window: public QWidget
{
    Q_OBJECT
public:
    Window();
    QPushButton* btn();
    QLineEdit* text();
    QLabel* labl();
    QLabel* labl1();
    QLabel* Img();
    void Store();


private:
    QPushButton *button;
    QLineEdit *txt;
    QLabel* label;
    QLabel* label1;
    QLabel* Image;
    QFont f;
    QVector<QLabel*> V;

};

#endif // WINDOW_H
