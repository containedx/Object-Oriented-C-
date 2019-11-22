#include "Small.h"
#include "BenchIncludes.h"
#include <unordered_set>
using namespace std;
/*
 empty, size, max_size,
    clear, insert, erase, swap,
    count, find, equal_range,
    rehash, reserve
 */

static void Sbench_empty(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        u.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_size(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        u.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_maxsize(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        u.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_clear(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            A[i].data[0] = rand();
            u.insert(A[i]);
        }
        state.ResumeTiming();

        u.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_insert(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A{};
    A.data[0] = rand();

    for(auto _: state)
    {
        u.insert(A);

        state.PauseTiming();
        u.erase(A);
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_erase(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A{};
    A.data[0] = rand();

    for(auto _: state)
    {
        state.PauseTiming();
        u.insert(A);
        state.ResumeTiming();

        u.erase(A);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_swap(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    unordered_multiset<Small> w;
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        u.insert(A[i]);
        w.insert(B[i]);
    }
    for(auto _: state)
    {
        u.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_count(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        u.count(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_count)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_find(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        u.find(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_find)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_equalrange(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        u.insert(A[i]);
    }
    for(auto _: state)
    {
        u.equal_range(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_equalrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_rehash(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
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
BENCHMARK(Sbench_rehash)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_reserve(State& state)
{
    auto N = state.range(0);
    unordered_multiset<Small> u;
    Small A[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
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
BENCHMARK(Sbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();