#include "clickableqlabel.h"

ClickableLabel::ClickableLabel(QString S):QLabel(S){

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();//Emission d'un signal lors du click sur le label desirer qui sera utiliser dans les connections
}

