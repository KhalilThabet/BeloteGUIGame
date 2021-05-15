#ifndef JOUEUR_H
#define JOUEUR_H
#include<QVector>
#include <QLabel>
#include <QPixmap>
class joueur
{
public:
    joueur();
    QVector<QLabel*>& getDosCarte();
private:
    QVector <QLabel*> dosdecartes;

};

#endif // JOUEUR_H
