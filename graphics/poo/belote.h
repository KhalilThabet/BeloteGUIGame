#ifndef BELOTE_H
#define BELOTE_H

#include <QMainWindow>
#include <QLabel>
#include <QString>

namespace Ui {
class belote;
}

class belote : public QMainWindow
{
    Q_OBJECT

public:
    explicit belote(QWidget *parent = nullptr);
    ~belote();

private:
    Ui::belote *ui;
    QLabel *outnomJ1;
public slots:
void recvText(const QString &text);
};

#endif // BELOTE_H
