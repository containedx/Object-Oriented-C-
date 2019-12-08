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

TEST( Universe, Simulate0)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe( time, space, observer);

    EXPECT_CALL(time, now()).WillOnce(Return(2));
    //EXPECT_CALL(time, flow()).Times(1).WillOnce(Invoke(sleep_mock));

    universe.simulate(0); // now>years => nie wejdzie nawet do petli while w simulate
}

TEST( Universe, Simulate1)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe( time, space, observer);

    long int i = 0;
    EXPECT_CALL(time, now()).WillOnce(Return(9300000000 )).WillRepeatedly(Return(9300000000+1));
    //EXPECT_CALL(time, now()).WillOnce(Return(9400000000));
    EXPECT_CALL(time, flow()).WillRepeatedly(Invoke(sleep_mock));
    EXPECT_CALL(observer, remember("Is there planet Earth?", "Yes!"));

    universe.simulate(9300000000+1);
}

TEST( Universe, Simulate2)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe( time, space, observer);

    long int i = 0;
    EXPECT_CALL(time, now()).WillOnce(Return(9900000000 )).WillRepeatedly(Return(9900000000+1));
    //EXPECT_CALL(time, now()).WillOnce(Return(9400000000));
    EXPECT_CALL(time, flow()).WillRepeatedly(Invoke(sleep_mock));
    EXPECT_CALL(observer, remember("Does life exist?", "Yes!"));

    universe.simulate(9900000000+1);
}

TEST( Universe, Simulate3)
{
    StrictMock<TimeMock> time{};
    StrictMock<SpaceMock> space{};
    StrictMock<ObserverMock> observer{};

    Universe universe( time, space, observer);

    long int i = 0;
    EXPECT_CALL(time, now()).WillOnce(Return(13800000000 )).WillRepeatedly(Return(13800000000+1));
    //EXPECT_CALL(time, now()).WillOnce(Return(9400000000));
    EXPECT_CALL(time, flow()).WillRepeatedly(Invoke(sleep_mock));
    EXPECT_CALL(observer, remember("Have People evolved?", "Yes!"));

    universe.simulate(13800000000+1);
}