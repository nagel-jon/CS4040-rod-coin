#ifndef SPARSECUT_H
#define SPARSECUT_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int sparse_cut_wrapped(vector<int>& lengths, vector<int>& prices, int n);


int memoized_cut_rod(vector<int>& lengths, vector<int>& prices, int n);
int memoized_cut_rod_aux(vector<int>& lengths, vector<int>& prices, int n, unordered_map<int, int>& memo);


int sparse_cut_wrapped(vector<int>& lengths, vector<int>& prices, int n){
    // int maxn = lengths.back();
    // int mod = n % maxn;
    // int maxcombo = memoized_cut_rod(lengths, prices, mod);

    // int maxmult = n / maxn;

    // int nmultiples = maxmult * memoized_cut_rod(lengths, prices, maxn);

    // return nmultiples + maxcombo;
    int maxn = lengths.back();
    int mod = n % maxn;
    int maxcombo = memoized_cut_rod(lengths, prices, mod);

    int maxmult = n / maxn;

    int nmultiples = maxmult * maxcombo;

    return nmultiples + maxcombo;


}




int memoized_cut_rod(vector<int>& lengths, vector<int>& prices, int n) {
    unordered_map<int, int> memo;
    return memoized_cut_rod_aux(lengths, prices, n, memo);
}

int memoized_cut_rod_aux(vector<int>& lengths, vector<int>& prices, int n, unordered_map<int, int>& memo) {
    int q;

    if (memo.find(n) != memo.end()) {
        // If the result for length n is already memoized, return it
        return memo[n];
    }

    if (n == 0) {
        // If n = 0, return 0
        q = 0;
    } else {
        q = -1;
        for (int i = 0; i < lengths.size(); i++) {
            // Check if the length is less than or equal to the remaining rod length
            if (lengths[i] <= n) {
                // Recursively calculate the value for the remaining length
                int remaining_value = memoized_cut_rod_aux(lengths, prices, n - lengths[i], memo);
                q = max(q, prices[i] + remaining_value);
            }
        }
    }

    // Memoize the result for length n
    memo[n] = q;
    return q;
}




#endif

