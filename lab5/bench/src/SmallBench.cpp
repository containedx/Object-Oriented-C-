#include "Small.h"
#include "BenchIncludes.h"

// TODO: Add benchmarks for operator<. operator==, and hash

static void Operator1( State& state )
{
    for (auto _ : state)
    {
        Small A{};
        Small B{};

        auto operation = A < B;

        DoNotOptimize(&state);
    }
   // state.SetComplexityN(state.range(0)); NIEPOTRZEBNE !!
}

BENCHMARK( Operator1 ) //->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity(); nie mierzyc zlozonosci xd
                        // zmierzyc tylko ile trwaa 1 porownanie

static void Operator2( State& state )
{
    for (auto _ : state)
    {
        Small A{};
        Small B{};

        auto operation = A == B;

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( Operator2 )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();

static void Hashing( State& state )
{
    for (auto _ : state)
    {
        Small A{};
        std::hash<Small> hash;
        auto operation = hash(A);

        DoNotOptimize(&state);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK( Hashing )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();