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
static int t[1001][1001];

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
}

int main(void) {

  vector<int> weight = input_arr(cin);
  vector<int> value = input_arr(cin);
  size_t bag_weight{};
  cin >> bag_weight;

  // t.reserve(1e6 + 1);
  memset(t, -1, sizeof(t));

  cout << knapsack01(0, bag_weight, weight, value) << endl;

  return 0;
}
