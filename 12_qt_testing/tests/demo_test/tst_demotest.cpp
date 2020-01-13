#include <QtTest>

#include "demo.h"
#include <QSignalSpy>

// add necessary includes here

class DemoTest : public QObject
{
    Q_OBJECT

public:


private slots:
    void test_case1()
    {
        //QCOMPARE(1,2);
        //QVERIFY(true); //true lub false
        Demo demo{};

        QSignalSpy spy(&demo, SIGNAL(added()));

        QCOMPARE(10, demo.add(2,8));

        QCOMPARE( 1, spy.count());

        //testowanie wlasciwosci
        demo.property("value");
        demo.setProperty("value", 10);
    }

};


QTEST_APPLESS_MAIN(DemoTest)

#include "tst_demotest.moc"
