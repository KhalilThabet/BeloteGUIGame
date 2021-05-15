#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openbelote();
    void sendText(QWidget *parent);
signals:
void textChanged(const QString &text);



private:
    Ui::MainWindow *ui;
private:
    QLineEdit *inputnomJ1;
};
#endif // MAINWINDOW_H
