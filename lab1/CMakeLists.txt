cmake_minimum_required(VERSION 3.14) 
project(nothing_lib) 

#### creating library
add_library(nothing_lib STATIC src/nothing.cpp)
target_include_directories(nothing_lib PUBLIC include)

add_executable(nothing_bin src/main.cpp)
target_link_libraries( nothing_bin nothing_lib )

### test
include_directories(../googletest/googletest/include)
link_directories(../googletest/build/lib)

add_executable(test test.cpp )
target_link_libraries(test gtest gtest_main pthread)
target_link_libraries( test nothing_lib )
