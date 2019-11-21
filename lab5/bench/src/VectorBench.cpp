#include "Small.h"
#include "BenchIncludes.h"
#include <vector>
#include <random>

using namespace std;
/*
 at, operator[], front, back, data,
    empty, size, max_size, reserve, capacity, shrink_to_fit,
    clear, insert, erase, push_back, pop_back, resize, swap
 */

static void Sbench_at(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.at(0);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_operator(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v[0];
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_operator)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_front(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.front();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_front)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_back(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.back();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_back)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_data(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.data();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_data)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_empty(State& state)
{
    Small A{};
    vector<Small> v = {A};

    for(auto _ : state)
    {
        v.empty();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_size(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_maxsize(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.max_size();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_reserve(State& state)
{
    Small A{};
    vector<Small> v = {A};

    for(auto _ : state)
    {
        auto n = rand();
        v.reserve(n);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_capacity(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        v.capacity();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_capacity)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_shrink(State& state)
{
    auto N = state.range(0);

    for(auto _ : state)
    {
        state.PauseTiming();
        vector<Small> v(N);
        v.resize(10);
        state.ResumeTiming();

        v.shrink_to_fit();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_shrink)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_clear(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v;


    for(auto _ : state)
    {
        state.PauseTiming();
        for (int i = 0; i < 10; i++)
        {
            tab[i].data[0] = rand();
            v.push_back(tab[i]);
        }
        state.ResumeTiming();

        v.clear();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_clear)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_insert(State& state)
{
    Small A{};
    vector<Small> v = {};

    for(auto _ : state)
    {
        v.insert(v.begin(), A);

        state.PauseTiming();
        v.erase(v.begin());
        state.ResumeTiming();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_insert)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_erase(State& state)
{
    Small tab[10];
    vector<Small> v;
    for (int i = 0; i < 10; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        state.PauseTiming();
        auto it = v.begin();
        Small A{};
        A.data[0] = rand();
        v.insert(it, A);
        state.ResumeTiming();

        v.erase(it);
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_erase)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_pushback(State& state)
{
    Small A{};
    vector<Small> v = {};

    for(auto _ : state)
    {
        v.push_back(A);

        state.PauseTiming();
        v.pop_back();
        state.ResumeTiming();
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_pushback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_popback(State& state)
{
    auto N = state.range(0);
    Small A{};
    A.data[0] = rand();
    vector<Small> v = {};

    for(auto _ : state)
    {
        state.PauseTiming();
        v.push_back(A);
        state.ResumeTiming();

        v.pop_back();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_popback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_resize(State& state)
{
    auto N = state.range(0);
    for(auto _ : state)
    {
        state.PauseTiming();
        vector<Small>v(N);
        state.ResumeTiming();

        v.resize(3);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_resize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_swap(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    Small tab2[N];
    vector<Small> v;
    vector<Small> w;
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        tab2[i].data[0] = rand();

        v.push_back(tab[i]);
        w.push_back(tab2[i]);
    }

    for(auto _ : state)
    {
        v.swap(w);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();