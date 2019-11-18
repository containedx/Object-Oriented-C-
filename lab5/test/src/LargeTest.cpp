#include "TestIncludes.h"

#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include "Large.h"

TEST(LargeTest, SizeIsOneMegabyte) {

    EXPECT_EQ(1024u*1024u, sizeof(Large));
}

TEST(LargeTest, CreateObject) {

    Large large{};
}

TEST(LargeTest, HasLessThenOperator) {

    Large a{};
    Large b{};

    a < b;
}

TEST(LargeTest, HasEqualityOperator) {

    Large a{};
    Large b{};

    a == b;
}

TEST(LargeTest, CanBeHashed) {

    Large large{};
    std::hash<Large> hash;

    hash(large);
}

TEST(LargeTest, Collections) {

    Large large{};

    std::vector<Large> vector{};
    vector.push_back(large);

    std::array<Large, 1> array{};
    array[0] = large;

    std::deque<Large> deque{};
    deque.push_back(large);

    std::list<Large> list{};
    list.push_back(large);

    std::forward_list<Large> forward_list{};
    forward_list.push_front(large);

    std::map<Large, bool> map{};
    map[large] = true;

    std::set<Large> set{};
    set.insert(large);

    std::unordered_map<Large, bool> unordered_map{};
    unordered_map[large] = true;

    std::unordered_set<Large> unordered_set{};
    unordered_set.insert(large);
}

TEST(LargeTest, Randomize) {

    Large large{};
    large.randomize();

    auto count = 0u;

    for (double i : large.data) {

        ASSERT_LE(0.0, i);
        ASSERT_GE(1.0, i);

        if (i != 0.0)
            ++count;
    }

    EXPECT_NE(0u, count) << "All elements were zero?";
}

TEST(LargeTest, Clear) {

    Large large{};
    large.randomize();
    large.clear();

    for (double i : large.data) {
        ASSERT_DOUBLE_EQ(0.0, i);
    }
}



TEST( LargeTestMyOperator, Operatorless)
{
    Large A{};
    Large B{};

    for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i;
        B.data[i] = i+1;
    }

    EXPECT_EQ(true, A < B);
}


TEST( MediumTestOperator1, Operatorless2)
{
    Large A{};
    Large B{};

    for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i+10;
        B.data[i] = i+1;
    }

    EXPECT_EQ(false, A < B);
}

TEST( LargeTestMyOperatorLessWhenEqual, Operatorless)
{
    Large A{};
    Large B{};
    A.randomize();

    for(int i=0; i<(128u*1024); i++)
    {
        B.data[i] = A.data[i];
    }

    EXPECT_EQ(false, A < B);
}

TEST( LargeTestMyOperator2, Operatorequal)
{
    Large A{};
    Large B{};

    for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i;
        B.data[i] = i;
    }

    EXPECT_EQ(true, A == B);
}


TEST( LargeTestMyOperator3, Operatorequal2)
{
    Large A{};
    Large B{};
    A.randomize();
    B.randomize();

    EXPECT_EQ(false, A == B);
}


TEST( LargeTestMyHash, Hash)
{
    Large A{};
    Large B{};

    for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i;
        B.data[i] = i;
    }
    std::hash<Large> hash;

    EXPECT_EQ(hash(B), hash(A));
}

TEST( LargeTestMyHash2, Hash2)
{
    Large A{};
    Large B{};
    A.randomize();

    for(int i=0; i<128u*1024u; i++)
    {
        B.data[i] = A.data[i];
    }
    std::hash<Large> hash;
    EXPECT_EQ(hash(B), hash(A));
}
