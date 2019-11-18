set(BENCH_HEADERS include/BenchIncludes.h)
set(BENCH_SOURCES src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp src/VectorBench.cpp src/MapBench.cpp src/UnorderedMultisetBench.cpp)

add_executable(05_stl_benchmark_bench ${BENCH_HEADERS} ${BENCH_SOURCES})
target_include_directories(05_stl_benchmark_bench PUBLIC include)
target_link_libraries(05_stl_benchmark_bench 05_stl_benchmark_lib benchmark benchmark_main pthread)
