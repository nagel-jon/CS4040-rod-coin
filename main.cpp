#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#include "coinchange.h"
#include "sparsecut.h"

/*
1. Sparse Rod Cutting Problem
Given a rod of length n, what cuts will produce the most revenue?
Sparse Change - May be given lengths larger than biggest length in table
Must cut down these lengths to a combination of lenghts in table
*/

/*
2. Coin Change Problem
*/

int main() {

  vector<int> price = {1, 5, 9, 17, 20, 30, 36, 48}; // Sample price vector

  vector<int> lengths = {1, 2, 4, 6, 8, 10, 12, 16}; // Sample lengths vector

  vector<int> tests = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

  for (int i = 0; i < tests.size(); ++i) {
    auto startTime = std::chrono::high_resolution_clock::now();
    int result = sparse_cut(price, lengths, tests[i]);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime);

    std::cout << "Time taken by sparse_cut for input " << tests[i] << ": "
              << duration.count() << " nanoseconds." << std::endl;
    std::cout << "Sparse Cut Result For: " << tests[i] << " -> " << result
              << std::endl;
  }

    int x = 10;
    int coins[] = {1, 2, 5};
    int num_coins = sizeof(coins) / sizeof(coins[0]);

    std::vector<std::vector<int>> combinations;
    int num_combinations = getNumCombinations(x, coins, num_coins, combinations);

    std::cout << "Number of Unique Combinations: " << num_combinations << "\n";

    if (num_combinations > 0) {
        printCombinations(x, coins, num_coins, combinations);
    }

  return 0;
}
