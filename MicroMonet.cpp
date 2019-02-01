#include <benchmark/benchmark.h>
#include <iostream>
#include "ittnotify.h"

using namespace std;

long long inputSize = 4 * 33554432;
static void selection(benchmark::State& state) {
  auto value = state.range(0);
  auto input = new int[inputSize];

  for(size_t i = 0; i < inputSize; i++)
    input[i] = (i * 12343) % 499;

  for(auto _ : state) {
  }
	benchmark::DoNotOptimize(input);
	delete[] input;
}

BENCHMARK(selection)
    ->Args(1 * 50)
    ->Args(2 * 50)
    ->Args(3 * 50)
    ->Args(4 * 50)
    ->Args(5 * 50)
    ->Args(6 * 50)
    ->Args(7 * 50)
    ->Args(8 * 50)
    ->Args(9 * 50)
    ->Args(10 * 50)
    ->Args(11 * 50);

BENCHMARK_MAIN();
