#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT
    //Classe Fille de Qlabel qui aura toutes les propriete de la classe mere mais avec une propriete qui reagit aux clicks de la sourie

public:
    explicit ClickableLabel(QString);
    ~ClickableLabel();
signals:
    void clicked();
    void Screen();


protected:
    void mousePressEvent(QMouseEvent* event); //Fonction qui servira a capter l'evenement de la sourie par rapport a l'objet creer


};

#endif // CLICKABLELABEL_H
