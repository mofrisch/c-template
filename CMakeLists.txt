cmake_minimum_required(VERSION 3.19)
get_filename_component(my_project ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${my_project})

include(CTest)
enable_testing()

add_executable(${my_project} main.c)
add_executable(bench bench/main.cpp src/armstrong_numbers.c)

set_target_properties(${my_project} PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED ON
    C_EXTENSIONS OFF
)

set_target_properties(bench PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

add_compile_options(-Wall -Wextra -pedantic -Werror -O3)

find_package(benchmark REQUIRED)
target_link_libraries(bench PRIVATE benchmark::benchmark)
include_directories("/usr/local/include")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
