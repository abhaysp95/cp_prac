#include <bits/stdc++.h>
#include <cstring>
#include <numeric>
#include <sstream>

using namespace std;

vector<int> input_arr(istream &in) {
  vector<int> arr{};
  string input{};

  in >> input;

  stringstream istream{input};
  string temp{};
  while (getline(istream, temp, ',')) {
    arr.emplace_back(stoi(temp));
  }

  return arr;
}

// static vector<vector<int>> t;
/* static int t[1001][1001];

int knapsack01(size_t idx, int wt, const vector<int> &weight,
               const vector<int> &value) {
  if (weight.size() == idx || wt == 0) {
    return 0;
  }

  if (t[idx][wt] != -1) {
          return t[idx][wt];
  }
  if (weight[idx] <= wt) {
    return t[idx][wt] = max(value[idx] +
                   knapsack01(idx + 1, wt - weight[idx], weight, value),
               knapsack01(idx + 1, wt, weight, value));
  } else {
    return t[idx][wt] = knapsack01(idx + 1, wt, weight, value);
  }
} */

static int t[1001][1001];

int knapsack01_mem(int n, int w, const vector<int> &weight,
                   const vector<int> &value) {
  if (n == 0 || w == 0) {
    return 0;
  }

  if (t[n][w] != -1) {
    return t[n][w];
  }
  if (w <= weight[n - 1]) {
    return t[n][w] = max(value[n - 1] + knapsack01_mem(n - 1, w - weight[n - 1], weight, value), knapsack01_mem(n - 1, w, weight, value));
  } else {
    return t[n][w] = knapsack01_mem(n - 1, w, weight, value);
  }
}

int knapsack01(const vector<int> &weight, const vector<int> &value, int wt) {
  size_t sz = weight.size();
  int t[sz + 1][wt + 1];
  memset(t, 0, sizeof(t));

  for (size_t i{}; i <= sz; i++) {
    for (size_t j{}; j <= wt; j++) {
      if (i == 0 || j == 0) {
        t[i][j] = 0;
      } else {
        if (weight[i - 1] <= j) {
          t[i][j] =
              max(value[i - 1] + t[i - 1][j - weight[i - 1]], t[i - 1][j]);
        } else {
          t[i][j] = t[i - 1][j];
        }
      }
    }
  }

  return t[sz][wt];
}

int main(void) {

  vector<int> weight = input_arr(cin);
  vector<int> value = input_arr(cin);
  size_t bag_weight{};
  cin >> bag_weight;

  // t.reserve(1e6 + 1);
  // memset(t, -1, sizeof(t));

  cout << knapsack01(weight, value, bag_weight) << endl;

  return 0;
}
