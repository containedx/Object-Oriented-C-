#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash
static void MediumOperator10( State& state )
{
    Medium A{};
    Medium B{};
    for(int i=0; i< 256; i++)
    {
        A.data[i] = i;
        B.data[i] = i+1;
    }
    for (auto _ : state)
    {
        auto operation = A < B;
    }
}

BENCHMARK( MediumOperator10 );

static void MediumOperator20( State& state )
{
    Medium A{};
    Medium B{};
    for(int i=0; i< 256; i++)
    {
        A.data[i] = i;
        B.data[i] = i+1;
    }

    for (auto _ : state)
    {
        auto operation = A == B;
    }
}

BENCHMARK( MediumOperator20 );

static void MediumHashing0( State& state )
{
    Medium A{};
    for(int i=0; i< 256; i++)
    {
        A.data[i] = i;
    }
    for (auto _ : state)
    {
        std::hash<Medium> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( MediumHashing0 );

//random data:
static void MediumOperator1( State& state )
{
    Medium A{};
    Medium B{};
    A.randomize();
    B.randomize();
    for (auto _ : state)
    {
        auto operation = A < B;
    }
}

BENCHMARK( MediumOperator1 );

static void MediumOperator2( State& state )
{
    Medium A{};
    Medium B{};
    A.randomize();
    B.randomize();
    for (auto _ : state)
    {
        auto operation = A == B;
    }
}

BENCHMARK( MediumOperator2 );

static void MediumHashing( State& state )
{
    Medium A{};
    A.randomize();
    for (auto _ : state)
    {
        std::hash<Medium> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( MediumHashing );

