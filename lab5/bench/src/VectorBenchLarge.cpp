#include "Large.h"
#include "BenchIncludes.h"
#include <vector>
using namespace std;

static void Lbench_at(State& state)
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
        v.at(0);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_operator(State& state)
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
        v[0];
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_operator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_front(State& state)
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
        v.front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_front)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_back(State& state)
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
        v.back();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_back)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_data(State& state)
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
        v.data();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_data)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_empty(State& state)
{
    Large A{};
    vector<Large> v = {A};

    for(auto _ : state)
    {
        v.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Lbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_size(State& state)
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
        v.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_maxsize(State& state)
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
        v.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_reserve(State& state)
{
    Large A{};
    vector<Large> v = {A};

    for(auto _ : state)
    {
        auto n = rand()%10;
        v.reserve(n);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Lbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_capacity(State& state)
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
        v.capacity();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_capacity)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_shrink(State& state)
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
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Lbench_shrink)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_clear(State& state)
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
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_insert(State& state)
{
    Large A{};
    vector<Large> v = {};

    for(auto _ : state)
    {
        v.insert(v.begin(), A);

        state.PauseTiming();
        v.erase(v.begin());
        state.ResumeTiming();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Lbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_erase(State& state)
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

        v.erase(it);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Lbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_pushback(State& state)
{
    Large A{};
    vector<Large> v = {};

    for(auto _ : state)
    {
        v.push_back(A);

        state.PauseTiming();
        v.pop_back();
        state.ResumeTiming();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Lbench_pushback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_popback(State& state)
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
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_popback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_resize(State& state)
{
    auto N = state.range(0);
    for(auto _ : state)
    {
        state.PauseTiming();
        vector<Large>v(N);
        int n = rand()%10;
        state.ResumeTiming();

        v.resize(n);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_resize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Lbench_swap(State& state)
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
        v.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Lbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();