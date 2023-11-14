#include <iostream>
#include <vector>
#ifndef COINCHANGE_H
#define COINCHANGE_H


int getNumCombinations(int x, int coins[], int num_coins, std::vector<std::vector<int>>& combinations) {
    // Initialize a 2D array to store combinations
    combinations.resize(x + 1, std::vector<int>(num_coins, 0));

    // Base case: There is one way to make change for 0
    for (int i = 0; i < num_coins; ++i) {
        combinations[0][i] = 1;
    }

    // Fill the combinations array using the dynamic programming approach
    for (int i = 0; i < num_coins; ++i) {
        int coin_value = coins[i];
        for (int j = coin_value; j <= x; ++j) {
            combinations[j][i] = combinations[j - coin_value][i] + ((i > 0) ? combinations[j][i - 1] : 0);
        }
    }

    // The result is stored in the bottom-right cell of the combinations array
    return combinations[x][num_coins - 1];
}

// Function to print all unique combinations
void printCombinations(int x, int coins[], int num_coins, std::vector<std::vector<int>>& combinations) {
    // Initialize vectors to store the current combination
    std::vector<int> current_combination;
    
    // Start from the bottom-right cell of the combinations array
    int i = x, j = num_coins - 1;

    // Traverse the combinations array to reconstruct the solution
    while (i > 0 && j >= 0) {
        if (j > 0 && combinations[i][j] == combinations[i][j - 1]) {
            // Move to the previous coin (skip duplicates)
            --j;
        } else {
            // Include the current coin in the combination
            current_combination.push_back(coins[j]);
            i -= coins[j];
        }
    }

    // Print the unique combinations
    std::cout << "Unique Combinations:\n";
    for (int k = current_combination.size() - 1; k >= 0; --k) {
        std::cout << current_combination[k] << " ";
    }
    std::cout << "\n";
}




#endif