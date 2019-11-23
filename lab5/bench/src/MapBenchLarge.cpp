#include "Large.h"
#include "BenchIncludes.h"
#include <map>
using namespace std;

static void Lbench_at(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.at(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();


static void Lbench_operator(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m[A[0]];
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_operator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_empty(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.empty();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_size(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m;
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_maxsize(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m;
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_clear(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m;
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
    }

    for(auto _: state)
    {
        state.PauseTiming();
        for(int i=0; i<N; i++)
        {
            m.insert({A[i],B[i]});
        }
        state.ResumeTiming();

        m.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_insert(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m;
    Large A {};
    Large B{};
    A.randomize();
    B.randomize();

    for(auto _: state)
    {
        m.insert({A,B});

        state.PauseTiming();
        m.erase(A);
        state.ResumeTiming();

    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_erase(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m;
    Large A {};
    Large B{};
    A.randomize();
    B.randomize();

    for(auto _: state)
    {
        state.PauseTiming();
        m.insert({A,B});
        state.ResumeTiming();

        m.erase(A);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_swap(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m;
    map <Large, Large> w;
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
        w.insert({B[i], A[i]});
    }

    for(auto _: state)
    {
        m.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_count(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.count(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_count)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_find(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.find(A[5]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_find)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_equalrange(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.equal_range(B[5]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_equalrange)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_lowerbound(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.lower_bound(A[5]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_lowerbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_upperbound(State& state)
{
    auto N = state.range(0);
    map <Large, Large> m{};
    Large A[N];
    Large B[N];
    for(int i=0; i<N; i++)
    {
        A[i].randomize();
        B[i].randomize();
        m.insert({A[i],B[i]});
    }

    for(auto _: state)
    {
        m.upper_bound(A[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_upperbound)->RangeMultiplier(2)->Range(1, 1024)->Complexity();