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

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( LargeOperator1 )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();

static void LargeOperator2( State& state )
{
    for (auto _ : state)
    {
        Large A{};
        Large B{};
        A.randomize();
        B.randomize();

        auto operation = A == B;

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( LargeOperator2 )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();

static void LargeHashing( State& state )
{
    for (auto _ : state)
    {
        Large A{};
        A.randomize();
        std::hash<Large> hash;
        auto operation = hash(A);

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( LargeHashing )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();
