#include "Universe.h"
#include "TestIncludes.h"

class TimeMock : public Time {
public:
    MOCK_METHOD1(create, void(bool endless));
    MOCK_CONST_METHOD0(now, long long());
    MOCK_METHOD0(flow, void());
};

class ObserverMock : public Observer {
public:
    MOCK_METHOD2(remember, void(std::string question, std::string answer));
    MOCK_CONST_METHOD1(answer, std::string(std::string question));
};

class SpaceMock : public Space {
public:
    MOCK_METHOD1(create, void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions, unsigned int());
};

void sleep_mock()
{
    sleep(0);
}

TEST(Universe, Create)
{
    //Nie mozna zmieniac zawartosci klasy Unniverse!
    //mozemy zmieniac w time space etc

    //zaimplementowac klase na potrzeby testow
    //Klasa time - interfejs
    // time impl - kod z time, nowa timecostam - implementacja na potrzeby testow
   /* przyklad:
    StrictMock<MyMock> myMock{};
    EXPECT_CALL( myMock, test()).willOnce( Return(10));

    EXPECT_EQ(10, dummy.execute());
    */

   StrictMock<TimeMock> time{};
   StrictMock<SpaceMock> space{};
   StrictMock<ObserverMock> observer{};

   EXPECT_CALL(time, create(true));
   EXPECT_CALL(space, create(11));
   EXPECT_CALL(space, dimensions()).WillOnce(Return(11));
   EXPECT_CALL(observer, remember("How many dimensions there are?", "11"));

   Universe universe( time, space, observer);

   universe.create();

}

TEST( Universe, Simulate)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe( time, space, observer);

    EXPECT_CALL(time, now()).WillOnce(Return(9300000000));
    EXPECT_CALL(time, flow()).Times(1).WillOnce(Invoke(sleep_mock));

    universe.simulate(9300000000);

}