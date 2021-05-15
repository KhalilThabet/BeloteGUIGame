#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "belote.h"
#include <QWidget>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1300,700);
    inputnomJ1= new QLineEdit(this);

    connect(ui->boutonplay, SIGNAL(clicked()), this, SLOT(openbelote()));
    connect(ui->boutonplay, SIGNAL(clicked()),inputnomJ1,      SLOT(sendText(this)));
    connect(ui->inputnomJ1 , SIGNAL(textChanged(QString)),this,  SLOT(recvText(QString)));
    //connect(ui->inputnomJ1, SIGNAL(clicked()), this, SLOT(setText()));

}
void MainWindow:: openbelote()
{
    belote *b = new belote(this);
    b->show();
}
void MainWindow:: sendText(QWidget *parent)
{
    QString text = inputnomJ1->text();
    emit textChanged(text);

}


MainWindow::~MainWindow()
{
    delete ui;
}

