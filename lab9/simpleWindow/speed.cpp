#include "speed.h"
#include <QDebug>

Speed::Speed(QObject *parent) : QObject(parent)
{

}
void Speed::onDisplacementChange(double v)
{
    qDebug() << "Speed value:  " << v;
    emit changed(v);
}
