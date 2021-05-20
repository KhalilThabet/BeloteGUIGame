#include "DynamicWidget.h"
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>

DynamicWidget::DynamicWidget(QString s):
   m_movie(s)
{
   connect(
      &m_movie,
      SIGNAL(frameChanged(int)),
      this,
      SLOT(paintNewFrame(int)));
   m_movie.start();
}

void DynamicWidget::paintEvent(QPaintEvent *event)
{
   // First we extract the current frame
   QPixmap currentFrame = m_movie.currentPixmap();

   QRect frameRect = currentFrame.rect();

   // Only redraw when the frame is in the invalidated area
   frameRect.moveCenter(rect().center());
   if (frameRect.intersects(event->rect()))
   {
      QPainter painter(this);
      painter.drawPixmap(
         frameRect.left(),
         frameRect.top(),
         currentFrame);
   }
}
void DynamicWidget::paintNewFrame(int)
{
   repaint();
}
