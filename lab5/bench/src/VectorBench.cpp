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
    vector<Small> v(N);
    Small A{};
    A.data[0]=rand();
    v.push_back(A);

    for(auto _ : state)
    {
        DoNotOptimize(v.at(0));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_at)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_operator(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v[0]);
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_operator)->RangeMultiplier(2)->Range(1, 1024 )->Complexity();

static void Sbench_front(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.front());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_front)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_back(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.back());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_back)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_data(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_data)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_empty(State& state)
{
    auto N = state.range(0);
    Small A{};
    vector<Small> v(N);
    v.push_back(A);

    for(auto _ : state)
    {
        DoNotOptimize(v.empty());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_empty)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_size(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_size)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_maxsize(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.max_size());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_maxsize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_reserve(State& state)
{
    auto N = state.range(0);
    Small A{};
    vector<Small> v(N);
    v.push_back(A);

    for(auto _ : state)
    {
        auto n = rand()%10;
        v.reserve(n);
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(Sbench_reserve)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_capacity(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        v.push_back(tab[i]);
    }

    for(auto _ : state)
    {
        DoNotOptimize(v.capacity());
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
        int num = rand()%10;
        v.resize(num);
        state.ResumeTiming();

        v.shrink_to_fit();
        DoNotOptimize(v.data());

    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_shrink)->RangeMultiplier(2)->Range(1, 1<<20)->Complexity();

static void Sbench_clear(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    vector<Small> v(N);


    for(auto _ : state)
    {
        state.PauseTiming();
        for (int i = 0; i < 10; i++)
        {
            tab[i].data[0] = rand();
            DoNotOptimize(v.data());
            v.push_back(tab[i]);
            ClobberMemory();
        }
        state.ResumeTiming();

        v.clear();
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_clear)->RangeMultiplier(2)->Range(1, 1<<20)->Complexity();

static void Sbench_insert(State& state)
{
    auto N = state.range(0);
    Small A{};
    vector<Small> v(N);

    for(auto _ : state)
    {
        DoNotOptimize(v.insert(v.begin(), A));

        state.PauseTiming();
        v.erase(v.begin());
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_insert)->RangeMultiplier(2)->Range(1, 1<<20)->Complexity();

static void Sbench_erase(State& state)
{
    auto N = state.range(0);
    Small tab[10];
    vector<Small> v(N);
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

        DoNotOptimize(v.erase(it));
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_erase)->RangeMultiplier(2)->Range(1, 1<<20)->Complexity();

static void Sbench_pushback(State& state)
{
    auto N = state.range(0);
    Small A{};
    vector<Small> v(N);

    for(auto _ : state)
    {
        DoNotOptimize(v.data());
        v.push_back(A);
        ClobberMemory();

        state.PauseTiming();
        v.pop_back();
        state.ResumeTiming();
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_pushback)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_popback(State& state)
{
    auto N = state.range(0);
    Small A{};
    vector<Small> v(N);

    for(auto _ : state)
    {
        state.PauseTiming();
        A.data[0] = rand();
        v.push_back(A);
        state.ResumeTiming();

        v.pop_back();
        DoNotOptimize(v.data());
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
        int num = rand()%10;
        state.ResumeTiming();

        v.resize(num);
        DoNotOptimize(v.data());
    }
    state.SetComplexityN(N);
}
BENCHMARK(Sbench_resize)->RangeMultiplier(2)->Range(1, 1024)->Complexity();

static void Sbench_swap(State& state)
{
    auto N = state.range(0);
    Small tab[N];
    Small tab2[N];
    vector<Small> v(N);
    vector<Small> w(N);
    for (int i = 0; i < N; i++)
    {
        tab[i].data[0] = rand();
        tab2[i].data[0] = rand();

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
BENCHMARK(Sbench_swap)->RangeMultiplier(2)->Range(1, 1024)->Complexity();