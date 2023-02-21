#include <bits/stdc++.h>
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

int knapsack01(size_t idx, int wt, const vector<int> &weight,
               const vector<int> &value) {
  if (weight.size() == idx || wt == 0) {
    return 0;
  }

  if (weight[idx] <= wt) {
    return max(value[idx] +
                   knapsack01(idx + 1, wt - weight[idx], weight, value),
               knapsack01(idx + 1, wt, weight, value));
  } else {
    return knapsack01(idx + 1, wt, weight, value);
  }
}

int main(void) {

  vector<int> weight = input_arr(cin);
  vector<int> value = input_arr(cin);
  size_t bag_weight{};
  cin >> bag_weight;

  cout << knapsack01(0, bag_weight, weight, value) << endl;

  return 0;
}
