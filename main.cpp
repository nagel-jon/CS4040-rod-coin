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

  // create vectors for sparse cut

  vector<int> price = {1, 5, 9, 17, 20, 30, 36, 48}; // Sample price vector

  vector<int> lengths = {1, 2, 4, 6, 8, 10, 12, 16}; // Sample lengths vector

  vector<int> tests = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096};

  // Sparse Cut Tests

  cout << "Time for Single Call to Sparse Cut: ";
  auto startTime = std::chrono::high_resolution_clock::now();
  int result = sparse_cut(price, lengths, 1);
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
  std::cout << duration.count() << " nanoseconds." << std::endl << endl;

  cout << "Sparse Cut Tests ---------------" << endl << endl;
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

  cout << endl;
  // coin change

  int us_coins[] = {1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000};

  vector<int> coin_experiments = {10,   50,   100,  500, 1000,
                                  1500, 2000, 3000, 5000};

  int num_us_coins = sizeof(us_coins) / sizeof(us_coins[0]);

  cout << "Original Coin Change Tests ---------------" << endl << endl;

  for (int i = 0; i < coin_experiments.size(); ++i) {
    auto startTime = std::chrono::high_resolution_clock::now();

    int result =
        original_coin_change(coin_experiments[i], us_coins, num_us_coins);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime);

    // Print the result and the time taken for each test
    std::cout << "Experiment input: " << coin_experiments[i] << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Time taken: " << duration.count() << " nanoseconds"
              << std::endl;
  }
  cout << endl;

  int wizard_coins[] = {1, 29, 493};
  int num_wizard_coins = sizeof(wizard_coins) / sizeof(wizard_coins[0]);

  cout << "Wizard Currency Coin Change Tests ---------------" << endl << endl;
  for (int i = 0; i < coin_experiments.size(); ++i) {
    auto startTime = std::chrono::high_resolution_clock::now();

    int result = original_coin_change(coin_experiments[i], wizard_coins,
                                      num_wizard_coins);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime);

    // Print the result and the time taken for each test
    std::cout << "Experiment input: " << coin_experiments[i] << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Time taken: " << duration.count() << " nanoseconds"
              << std::endl;
  }
  cout << endl;

  cout << "Reconstructing US Coin Change Tests ---------------" << endl << endl;

  int reconstruction_tests[]{10, 25, 50, 100, 200, 500};

  for (int i = 0;
       i < sizeof(reconstruction_tests) / sizeof(reconstruction_tests[0]);
       ++i) {
    cout << "Reconstructing for " << reconstruction_tests[i] << ": " << endl;
    auto startTime = std::chrono::high_resolution_clock::now();

    displayCoinCombinations(reconstruction_tests[i], us_coins, num_us_coins);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime);

    std::cout << "Experiment input: " << reconstruction_tests[i] << std::endl;
    std::cout << "Time taken: " << duration.count() << " nanoseconds"
              << std::endl;
  }

    cout << endl;

  cout << "Reconstructing Wizard Coin Change Tests ---------------" << endl << endl;


  for (int i = 0;
       i < sizeof(reconstruction_tests) / sizeof(reconstruction_tests[0]);
       ++i) {
    cout << "Reconstructing for " << reconstruction_tests[i] << ": " << endl;
    auto startTime = std::chrono::high_resolution_clock::now();

    displayCoinCombinations(reconstruction_tests[i], wizard_coins, num_wizard_coins);

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        endTime - startTime);

    std::cout << "Experiment input: " << reconstruction_tests[i] << std::endl;
    std::cout << "Time taken: " << duration.count() << " nanoseconds"
              << std::endl;
  }

  return 0;
}
