#include <QtTest>

// add necessary includes here

class Test1 : public QObject
{
    Q_OBJECT

public:


private slots:
    void test_case1();

};


void Test1::test_case1()
{
  //signal spy czy sygnaly wyemitowane i spawdzic argymenty
  //set property i property
}

QTEST_APPLESS_MAIN(Test1)

#include "tst_test1.moc"
