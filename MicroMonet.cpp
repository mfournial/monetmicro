#include <benchmark/benchmark.h>
#include <iostream>
#include "ittnotify.h"

using namespace std;

long long inputSize = 4 * 33554432;
static void intSelection(benchmark::State& state) {
  auto value = state.range(0);
  auto input = new int[inputSize];
  auto output = new int[inputSize];

  for(size_t i = 0; i < inputSize; i++)
    input[i] = (i * 12343) % 499;

  for(auto _ : state) {
    size_t j = 0;
    for(size_t i = 0; i < inputSize; i++) {
      output[j] = input[i];
      j += (input[i] < value);
    }
  }
	benchmark::DoNotOptimize(input);
	benchmark::DoNotOptimize(output);
	delete[] input;
  delete[] output;
}

static void candSelection(benchmark::State& state) {
  auto value = state.range(0);

  auto input = new int[inputSize];
  auto candidates = new size_t[inputSize];
  auto output = new size_t[inputSize+1];

  for(size_t i = 0; i < inputSize; i++)
    input[i] = (i * 12343) % 499;

  srand(time(nullptr));
  size_t cand_size = 0;
  for(size_t i = 0; i < inputSize; i++) {
    if (rand() % 2)
      candidates[cand_size++] = i;
  }

  for(auto _ : state) {
    int j = 0;
    for(size_t i = 0; i < cand_size; i++) {
      if (input[candidates[i]] < value)
        output[j++] = candidates[i];
    }
  }
	benchmark::DoNotOptimize(input);
	benchmark::DoNotOptimize(candidates);
	benchmark::DoNotOptimize(output);
	delete[] input;
  delete[] candidates;
  delete[] output;
}

BENCHMARK(intSelection)
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


BENCHMARK(candSelection)
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
