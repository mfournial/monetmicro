#include <benchmark/benchmark.h>
#include <iostream>
#include "ittnotify.h"

using namespace std;

long long inputSize = 4 * 33554432;
static void selection(benchmark::State& state) {
  auto value = state.range(0);
  auto input = new int[inputSize];
  auto output = new int[inputSize+1];

  for(size_t i = 0; i < inputSize; i++)
    input[i] = (i * 12343) % 499;

  for(auto _ : state) {
    int j = 1;
    for(size_t i = 0; i < inputSize; i++) {
      output[j] = input[i];
      j += (input[i] < value);
      /* res 1 - control dependency
      int cur = input[i];
      if (cur < value) {
        output[j++] = cur;
      }
      */
    }
  }
	benchmark::DoNotOptimize(input);
	benchmark::DoNotOptimize(output);
	delete[] input;
  delete[] output;
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
