#include "Small.h"
#include "BenchIncludes.h"
#include <map>

using namespace std;

/*
 at, operator[], empty, size, max_size,
    clear, insert, erase, swap,
    count, find, equal_range, lower_bound, upper_bound
 */

static void Sbench_at(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A{};
    Small B{};
    A.data[0] = rand();
    B.data[0] = rand();
    m.insert({A,B});

    for(auto _: state)
    {
       DoNotOptimize( m.at(A));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void Sbench_operator(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A{};
    Small B{};
    A.data[0] = rand();
    B.data[0] = rand();
    m.insert({A,B});

    for(auto _: state)
    {
        DoNotOptimize(m[A]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_operator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_empty(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_size(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m;
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_maxsize(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m;
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        DoNotOptimize(m.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_clear(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m;
    Small A[N];
    Small B[N];

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            A[i].data[0] = rand();
            B[i].data[0] = rand();
            m.insert({A[i],B[i]});
        }
        state.ResumeTiming();

        m.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_insert(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m;
    Small A {};
    Small B{};
    A.data[0] = rand();
    B.data[0] = rand();

    for(auto _: state)
    {
        DoNotOptimize(m.insert({A,B}));

        state.PauseTiming();
        m.erase(A);
        state.ResumeTiming();

    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_erase(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m;
    Small A {};
    Small B{};
    A.data[0] = rand();
    B.data[0] = rand();

    for(auto _: state)
    {
        state.PauseTiming();
        m.insert({A,B});
        state.ResumeTiming();

        DoNotOptimize(m.erase(A));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_swap(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m;
    map <Small, Small> w;
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
        w.insert({B[i], A[i]});
    }

    for(auto _: state)
    {
        m.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_count(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        int num = rand()%N;
        DoNotOptimize(m.count(A[num]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_count)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_find(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        int num = rand()%N;
        DoNotOptimize(m.find(A[N]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_find)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_equalrange(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        int num = rand()%N;
        DoNotOptimize(m.equal_range(A[num]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_equalrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_lowerbound(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        int num = rand()%N;
        DoNotOptimize(m.lower_bound(A[num]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_lowerbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_upperbound(State& state)
{
    auto N = state.range(0);
    map <Small, Small> m{};
    Small A[N];
    Small B[N];
    for(int i=0; i<N; i++)
    {
        A[i].data[0] = rand();
        B[i].data[0] = rand();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        int num = rand()%N;
        DoNotOptimize(m.upper_bound(A[num]));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_upperbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

