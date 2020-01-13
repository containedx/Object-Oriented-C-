#include <QtTest>
#include "fromlab11.h"

// add necessary includes here

class Test1 : public QObject
{
    Q_OBJECT

public:


private slots:
    void DisplacementTest();
    void SpeedTest();
    void AccelerationTest();

};



void Test1::DisplacementTest()
{
    Displacement D1{};
    QCOMPARE(1, D1.get());

    QSignalSpy spy(&D1, SIGNAL(changed(double)));

    double v = rand()%100;
    D1.set(v);
    QCOMPARE(v, D1.get());

    QCOMPARE( 1, spy.count());

    double x = rand()%100;
    D1.set(x);
    QCOMPARE(x, D1.get());

    QCOMPARE( 2, spy.count());

    D1.setProperty("value", 150);
    QCOMPARE(D1.property("value"), 150);
}

void Test1::SpeedTest()
{
    Speed S1{};
    QCOMPARE(S1.get(), NULL);

    QSignalSpy spy(&S1, SIGNAL(changed(double)));

    double v = rand()%40;
    S1.onChange(v);
    QCOMPARE(S1.get(), v);

    double x = rand()%50;
    S1.onChange(x);
    QCOMPARE(S1.get(), x - v);

    QCOMPARE(2, spy.count());

    double z = rand()%15;
    S1.onChange(z);
    QCOMPARE(S1.get(), z - x);

    QCOMPARE(3, spy.count());
}

void Test1::AccelerationTest()
{
    Acceleration A1{};
    QCOMPARE(A1.get(), NULL);

    QSignalSpy spy(&A1, SIGNAL(changed(double)));

    double v = rand()%5;
    A1.onChange(v);
    QCOMPARE(A1.get(), v);

    double x = rand()%9;
    A1.onChange(x);
    QCOMPARE(A1.get(), x - v);

    QCOMPARE(2, spy.count());

    double z = rand()%8;
    A1.onChange(z);
    QCOMPARE(A1.get(), z - x);

    QCOMPARE(3, spy.count());
}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"
