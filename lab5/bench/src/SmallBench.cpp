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
    state.SetComplexityN(state.range(0));
}

BENCHMARK( Operator1 )->RangeMultiplier(2)->Range(1<<10, 1<<18)->Complexity();