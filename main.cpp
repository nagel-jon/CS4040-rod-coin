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

  cout << "Sparse Cut Tests ---------------" << endl;
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
    // coin change

    int us_coins[] = {1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000};

    vector <int> us_experiments = {10, 50, 100, 500, 1000, 1500, 2000, 3000, 5000};

    int num_us_coins = sizeof(us_coins) / sizeof(us_coins[0]);

    cout << "Original Coin Change Tests ---------------" << endl;


    for (int i = 0; i < us_experiments.size(); ++i) {
        auto startTime = std::chrono::high_resolution_clock::now();
        
        int result = original_coin_change(us_experiments[i], us_coins, num_us_coins);
        
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);

        // Print the result and the time taken for each test
        std::cout << "Result: " << result << std::endl;
        std::cout << "Time taken: " << duration.count() << " nanoseconds" << std::endl;
    }

  return 0;
}
