#include <QCoreApplication>
#include "displacement.h"
#include "speed.h"
#include "acceleration.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Displacement d{};
    Speed s{};
    Acceleration a{};


    QObject::connect(&d,
                     SIGNAL(changed(double)),
                     &s,
                     SLOT(onDisplacementChange(double)) );

    QObject::connect(&d,
                     SIGNAL(changed(double)),
                     &a,
                     SLOT(onSpeedChanged(double)) );

    d.set(1);
    d.set(2);

    return app.exec();
}

/*
// QObject - klasa bazowa!!!
// projekty -> odznaczyc uruchom w terminalu

value = v;
 emit changed(value) ; emit - wysyla na zewnatrz sygnal ze cos tam sie zmienilo xd
 w pliku naglowkowym w
public signal:
 void changed(value);

 speed.h - obsluguje w slocie
 public slots:
  void onDisplacementChange(value);

  #include <QDebug> ->wypisywanie bledow na konsole

  speed.h
//public slots:
 //void onDisplacementChange(value);
 // cout ...
    //emit


 folder desktop debug -> make
*/
