#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QString);
    ~ClickableLabel();
signals:
    void clicked();
    void Screen();


protected:
    void mousePressEvent(QMouseEvent* event);


};

#endif // CLICKABLELABEL_H
