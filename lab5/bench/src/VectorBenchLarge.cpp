#include "Large.h"
#include "BenchIncludes.h"
#include <vector>
using namespace std;

static void Mbench_at(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.at(0));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_operator(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_operator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_front(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.front());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_front)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_back(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.back());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_back)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_data(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_data)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_empty(State& state)
{
    Large A{};
    vector<Large> v = {A};

    for(auto _ : state)
    {
        DoNotOptimize(v.empty());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Mbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_size(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_maxsize(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_reserve(State& state)
{
    Large A{};
    vector<Large> v = {A};

    for(auto _ : state)
    {
        auto n = rand()%10;
        v.reserve(n);
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Mbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_capacity(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.capacity());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_capacity)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_shrink(State& state)
{
    auto N = state.range(0);

    for(auto _ : state)
    {
        state.PauseTiming();
        vector<Large> v(N);
        int n = rand()%10;
        v.resize(n);
        state.ResumeTiming();


        v.shrink_to_fit();
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Mbench_shrink)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_clear(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    vector<Large> v;
    for(int i=0; i<N; i++)
    {
        tab[i].randomize();
    }


    for(auto _ : state)
    {
        state.PauseTiming();
        for (int i = 0; i < N; i++)
        {
            v.push_back(tab[i]);
        }
        state.ResumeTiming();

        v.clear();
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_insert(State& state)
{
    Large A{};
    vector<Large> v = {};

    for(auto _ : state)
    {
        DoNotOptimize(v.insert(v.begin(), A));

        state.PauseTiming();
        v.erase(v.begin());
        state.ResumeTiming();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Mbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_erase(State& state)
{
    Large tab[10];
    vector<Large> v;
    for (int i = 0; i < 10; i++)
    {
        tab[i].randomize();
        v.push_back(tab[i]);
    }
    Large A{};
    A.randomize();


    for(auto _ : state)
    {
        state.PauseTiming();
        auto it = v.begin();
        v.insert(it, A);
        state.ResumeTiming();

        DoNotOptimize(v.erase(it));
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Mbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_pushback(State& state)
{
    Large A{};
    vector<Large> v = {};

    for(auto _ : state)
    {
        DoNotOptimize(v.data());
        v.push_back(A);
        ClobberMemory();

        state.PauseTiming();
        v.pop_back();
        state.ResumeTiming();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Mbench_pushback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_popback(State& state)
{
    auto N = state.range(0);
    Large A{};
    A.randomize();
    vector<Large> v = {};

    for(auto _ : state)
    {
        state.PauseTiming();
        v.push_back(A);
        state.ResumeTiming();

        v.pop_back();
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_popback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_resize(State& state)
{
    auto N = state.range(0);
    for(auto _ : state)
    {
        state.PauseTiming();
        vector<Large>v(N);
        int n = rand()%10;
        state.ResumeTiming();

        v.resize(n);
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_resize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Mbench_swap(State& state)
{
    auto N = state.range(0);
    Large tab[N];
    Large tab2[N];
    vector<Large> v;
    vector<Large> w;
    for (int i = 0; i < N; i++)
    {
        tab[i].randomize();
        tab2[i].randomize();

        v.push_back(tab[i]);
        w.push_back(tab2[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.data());
        v.swap(w);
        ClobberMemory();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Mbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();