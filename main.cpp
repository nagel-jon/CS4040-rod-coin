#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    int n = 1; // Test different values of 'n'

for(int i = 0; i <= 10; i++){
    int result = sparse_cut_wrapped(price,lengths, i);
    std::cout << "Memoized Cut Rod Result: " << result << std::endl;
}


    
    return 0;
}


