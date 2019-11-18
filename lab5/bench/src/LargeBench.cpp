#include "Large.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

static void LargeOperator1( State& state )
{
    for (auto _ : state)
    {
        Large A{};
        Large B{};
        A.randomize();
        B.randomize();
        auto operation = A < B;
    }
}

BENCHMARK( LargeOperator1 );

static void LargeOperator2( State& state )
{
    for (auto _ : state)
    {
        Large A{};
        Large B{};
        A.randomize();
        B.randomize();
        auto operation = A == B;
    }
}

BENCHMARK( LargeOperator2 );

static void LargeHashing( State& state )
{
    for (auto _ : state)
    {
        Large A{};
        A.randomize();
        std::hash<Large> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( LargeHashing );
