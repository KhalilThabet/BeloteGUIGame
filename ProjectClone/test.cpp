#include "test.h"
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>

TsTestWidget::TsTestWidget(QString s):
   m_movie(s)
{
   connect(
      &m_movie,
      SIGNAL(frameChanged(int)),
      this,
      SLOT(paintNewFrame(int)));
   m_movie.start();
}

void TsTestWidget::paintEvent(QPaintEvent *event)
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
void TsTestWidget::paintNewFrame(int)
{
   repaint();
}
