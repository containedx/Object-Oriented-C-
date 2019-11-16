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

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( MediumOperator1 )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();

static void MediumOperator2( State& state )
{
    for (auto _ : state)
    {
        Medium A{};
        Medium B{};
        A.randomize();
        B.randomize();

        auto operation = A == B;

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( MediumOperator2 )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();

static void MediumHashing( State& state )
{
    for (auto _ : state)
    {
        Medium A{};
        A.randomize();
        std::hash<Medium> hash;
        auto operation = hash(A);

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( MediumHashing )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();