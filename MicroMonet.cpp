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
		// your code goes here
  }
	benchmark::DoNotOptimize(input);
	delete[] input;
}

BENCHMARK(selection)
    ->Arg(1 * 50)
    ->Arg(2 * 50)
    ->Arg(3 * 50)
    ->Arg(4 * 50)
    ->Arg(5 * 50)
    ->Arg(6 * 50)
    ->Arg(7 * 50)
    ->Arg(8 * 50)
    ->Arg(9 * 50)
    ->Arg(10 * 50)
    ->Arg(11 * 50);

BENCHMARK_MAIN();
