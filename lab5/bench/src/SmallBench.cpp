#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

static void SmallOperator1( State& state )
{
    for (auto _ : state)
    {
        Small A{};
        Small B{};
        auto operation = A < B;
    }
}

BENCHMARK( SmallOperator1 );

static void SmallOperator2( State& state )
{
    for (auto _ : state)
    {
        Small A{};
        Small B{};
        auto operation = A == B;
    }
}

BENCHMARK( SmallOperator2 );

static void SmallHashing( State& state )
{
    for (auto _ : state)
    {
        Small A{};
        std::hash<Small> hash;
        auto operation = hash(A);
    }
}

BENCHMARK( SmallHashing );