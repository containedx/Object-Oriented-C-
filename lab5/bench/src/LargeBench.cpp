#include "Large.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash
static void LargeOperator10( State& state )
{
    Large A{};
    Large B{};
    for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i;
        B.data[i] = i+1;
    }

    for (auto _ : state)
    {
        auto operation = A < B;
    }
}

BENCHMARK( LargeOperator10 );

static void LargeOperator20( State& state )
{
    Large A{};
    Large B{};
    for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i;
        B.data[i] = i+1;
    }

    for (auto _ : state)
    {
        auto operation = A == B;
    }
}

BENCHMARK( LargeOperator20 );

static void LargeHashing0( State& state )
{
    Large A{};
    A.randomize();for(int i=0; i<128u*1024u; i++)
    {
        A.data[i] = i;
    }

    for (auto _ : state)
    {
        std::hash<Large> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( LargeHashing0 );


//random data:
static void LargeOperator1( State& state )
{
    Large A{};
    Large B{};
    A.randomize();
    B.randomize();

    for (auto _ : state)
    {
        auto operation = A < B;
    }
}

BENCHMARK( LargeOperator1 );

static void LargeOperator2( State& state )
{
    Large A{};
    Large B{};
    A.randomize();
    B.randomize();

    for (auto _ : state)
    {
        auto operation = A == B;
    }
}

BENCHMARK( LargeOperator2 );

static void LargeHashing( State& state )
{
    Large A{};
    A.randomize();
    for (auto _ : state)
    {
        std::hash<Large> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( LargeHashing );
