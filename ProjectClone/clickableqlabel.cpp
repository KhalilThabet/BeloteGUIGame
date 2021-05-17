#include "clickableqlabel.h"

ClickableLabel::ClickableLabel(QString S):QLabel(S){

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}

