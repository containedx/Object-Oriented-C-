#include "Large.h"
#include "BenchIncludes.h"
#include <unordered_set>
using namespace std;

static void Lbench_empty(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u(N);

    for(auto _: state)
    {
        u.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_size(State& state)
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
        u.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_maxsize(State& state)
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
        u.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_clear(State& state)
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
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_insert(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Large> u;
    Large A{};
    A.randomize();

    for(auto _: state)
    {
        u.insert(A);

        state.PauseTiming();
        u.erase(A);
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_erase(State& state)
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

        u.erase(A);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_swap(State& state)
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
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_count(State& state)
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
        u.count(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_count)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_find(State& state)
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
        u.find(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_find)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_equalrange(State& state)
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
        u.equal_range(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_equalrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_rehash(State& state)
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
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_rehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_reserve(State& state)
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
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();