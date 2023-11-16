#ifndef SPARSECUT_H
#define SPARSECUT_H

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int sparse_cut(vector<int> &lengths, vector<int> &prices, int n);

int memoized_cut_rod(vector<int> &lengths, vector<int> &prices, int n);
int memoized_cut_rod_aux(vector<int> &lengths, vector<int> &prices, int n,
                         unordered_map<int, int> &memo);

int sparse_cut(vector<int> &lengths, vector<int> &prices, int n) {
    //cout << "entered sparse_cut" << endl;
  if (n > lengths.back()) {
    // n greater than longest length, need to break up into smaller lengths
    //cout << "entered if, n > max length in vector" << endl;
    int remainder = n % lengths.back();

    int remainder_value = memoized_cut_rod(lengths, prices, remainder);

    int number_n_multiples = (n - remainder) / lengths.back();

    int n_multiple_value =
        number_n_multiples * memoized_cut_rod(lengths, prices, lengths.back());

    return remainder_value + n_multiple_value;
  } else {
    //cout << "entered else, n <= max length in vector" << endl;
    return memoized_cut_rod(lengths, prices, n);
  }
}

int memoized_cut_rod(vector<int> &lengths, vector<int> &prices, int n) {
  vector<int> r(n + 1, -1);     // Initialize array to store solutions

//   cout << "printing r vector" << endl;
//     for (int i = 0; i < r.size(); i++) {
//         cout << r[i] << " ";
//     }
  unordered_map<int, int> memo; // Memoization table

  //cout << "memoization table created" << endl;

  //cout << "called cut aux" << endl;
  return memoized_cut_rod_aux(prices, r, n, memo);
}

int memoized_cut_rod_aux(vector<int> &prices, vector<int> &r, int n,
                         unordered_map<int, int> &memo) {
  if (r[n] >= 0) {
    //cout << "r[n] already in table, returning r[n]" << endl;
    return r[n];
  }

  int q;

  if (n == 0) {
    //cout << "n == 0, returning 0" << endl;
    q = 0;
  } else {
    q = -1;
    //cout << "entering for loop" << endl;
    for (int i = 1; i <= n && i < prices.size(); ++i) {
        //cout << "i = " << i << endl;
      q = max(q, prices[i - 1] + memoized_cut_rod_aux(prices, r, n - i, memo));
      //cout << "q = " << q << endl;
    }
  }

  r[n] = q;
  return q;
}



#endif
