#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_set>
using namespace std;

static void Mbench_empty(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(u.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_size(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(u.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_maxsize(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize( u.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_clear(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
    }

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            u.insert(A[i]);
        }
        state.ResumeTiming();

        u.clear();
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_insert(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A{};
    A.randomize();

    for(auto _: state)
    {
        DoNotOptimize(u.insert(A));

        state.PauseTiming();
        u.erase(A);
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_erase(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A{};
    A.randomize();

    for(auto _: state)
    {
        state.PauseTiming();
        u.insert(A);
        state.ResumeTiming();

        DoNotOptimize(u.erase(A));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_swap(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    unordered_multiset<Large> w;
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        u.insert(A[i]);
        w.insert(B[i]);
    }
    for(auto _: state)
    {
        u.swap(w);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_count(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(u.count(A[0]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_count)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_find(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(u.find(A[0]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_find)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_equalrange(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        DoNotOptimize(u.equal_range(A[0]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_equalrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_rehash(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        state.PauseTiming();
        int num = rand()%10;
        state.ResumeTiming();

        u.rehash(num);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_rehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_reserve(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        state.PauseTiming();
        int num = rand()%10;
        state.ResumeTiming();

        u.reserve(num);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();