#include "Medium.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

static void MediumOperator1( State& state )
{
    for (auto _ : state)
    {
        Medium A{};
        Medium B{};
        A.randomize();
        B.randomize();
        auto operation = A < B;
    }
}

BENCHMARK( MediumOperator1 );

static void MediumOperator2( State& state )
{
    for (auto _ : state)
    {
        Medium A{};
        Medium B{};
        A.randomize();
        B.randomize();
        auto operation = A == B;
    }
}

BENCHMARK( MediumOperator2 );

static void MediumHashing( State& state )
{
    for (auto _ : state)
    {
        Medium A{};
        A.randomize();
        std::hash<Medium> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( MediumHashing );