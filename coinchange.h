#include <iostream>
#include <vector>
#ifndef COINCHANGE_H
#define COINCHANGE_H


// Function to get all combinations of coins that can make change for the target amount 'x'
std::vector<std::vector<std::vector<int>>> getWaysWithCoins(int x, int coins[], int num_coins) {
    // Initialize a 3D vector 'ways' to store the coin combinations for each amount from 0 to x
    std::vector<std::vector<std::vector<int>>> ways(x + 1, std::vector<std::vector<int>>());

    // Base case: there is one way to make change for 0 (no coins)
    ways[0].push_back(std::vector<int>());

    // Iterate through each coin denomination
    for (int i = 0; i < num_coins; ++i) {
        // Get the value of the current coin
        int coin_value = coins[i];

        // Iterate through amounts from 'coin_value' to 'x'
        for (int j = coin_value; j <= x; ++j) {
            // Iterate through each combination of coins that can make change for 'j - coin_value'
            for (auto combination : ways[j - coin_value]) {
                // Add the current coin to the combination
                combination.push_back(coin_value);
                // Add the new combination to the ways for the current amount 'j'
                ways[j].push_back(combination);
            }
        }
    }

    // Return the 3D vector containing all coin combinations for each amount from 0 to x
    return ways;
}

// Function to call getWaysWithCoins and display the number of results and execution time
void displayCoinCombinations(int x, int coins[], int num_coins) {
    // Record start time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Get all coin combinations for making change for the target amount 'x'
    std::vector<std::vector<std::vector<int>>> result = getWaysWithCoins(x, coins, num_coins);

    // Record end time
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate and display the execution time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    std::cout << "Execution Time: " << duration.count() << " microseconds\n";

    // Display the number of coin combinations for the target amount 'x'
    std::cout << "Number of coin combinations for making change for " << x << ": " << result[x].size() << std::endl;

    // Display all combinations
    // std::cout << "All combinations:\n";
    // for (auto combination : result[x]) {
    //     for (auto coin : combination) {
    //         std::cout << coin << " ";
    //     }
    //     std::cout << std::endl;
    // }
}

int original_coin_change(int x, int coins[], int num_coins){
    std::vector<int> ways(x + 1, 0);
    ways[0] = 1;

    for(int i = 0; i < num_coins; ++i){
        for(int j = coins[i]; j <= x; ++j){
            ways[j] += ways[j - coins[i]];
        }
    }
    return ways[x];



}


#endif