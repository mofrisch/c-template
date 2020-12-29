cmake_minimum_required(VERSION 3.19)

# The project itself
get_filename_component(my_project ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${my_project})
add_executable(${my_project} main.c src/armstrong_numbers.c)
set_target_properties(${my_project} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)

# CTest and Google Test
include(CTest)
enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)
add_executable(tests tests/test.cpp tests/test2.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)
gtest_discover_tests(tests)
set_target_properties(tests PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Google benchmark
add_executable(bench bench/main.cpp src/armstrong_numbers.c)
find_package(benchmark REQUIRED)
target_link_libraries(bench PRIVATE benchmark::benchmark)
set_target_properties(bench PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Compiler options
add_compile_options(-Wall -Wextra -pedantic -Werror -O3)

# CPack
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
