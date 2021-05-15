#include "window.h"
#include <QVector>

Window::Window() : QWidget()
{


    this->setObjectName("Window");

    button=new QPushButton("Submit");
    button->setObjectName("button");

    txt=new QLineEdit("Input Player Name");
    txt->setObjectName("texte");
    label=new QLabel("JEU BELOTE");
    QString PlayerName;
    label->setStyleSheet("position:absolute;font-size:70px;background:white;border-radius:5px");
    label1=new QLabel("");
    label1->setAlignment(Qt::AlignCenter);
    label1->setStyleSheet("background:beige;border-radius:5px");
    label->setObjectName("label");
    label->setAlignment(Qt::AlignCenter);

    Image=new QLabel("<img src='C:/Users/Khali/OneDrive/Bureau/Qt Training/image.jpg'>");
    f.setPointSize(20);
    f.setBold(20);
    label->setFont(f);
    txt->setFixedSize(600,30);
    txt->setAlignment(Qt::AlignCenter);
    txt->setStyleSheet("border-radius:5px;text-alignement:20px");
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(Store()));
    QObject::connect(txt,SIGNAL(textChanged(QString)),label1,SLOT(setText(QString)));






}
void Window::Store(){
    V.push_back(label1);
    txt->clear();
}


QPushButton* Window::btn(){
    return button;
}
QLineEdit* Window::text(){
    return txt;
}

QLabel* Window::labl(){
    return label;
}
QLabel* Window::labl1(){
    return label1;
}
QLabel* Window::Img(){
    return Image;
}
