#include <inttypes.h>

#include <benchmark/benchmark.h>

#include "../src/armstrong_numbers.h"

static void BM_isa(benchmark::State &state) {
    for (auto _ : state)
        bool b = is_armstrong_number(9926315);
}

static void BM_isaold(benchmark::State &state) {
    for (auto _ : state)
        bool b = is_armstrong_number_old(9926315);
}

BENCHMARK(BM_isaold);
BENCHMARK(BM_isa);

BENCHMARK_MAIN();

/*
int main() {
    for (int i = 1; i < 10; ++i)
        for (int j = 0; j < 11; ++j)
            printf("%" PRIu64 "\n", ipow2(i, j));
}
*/