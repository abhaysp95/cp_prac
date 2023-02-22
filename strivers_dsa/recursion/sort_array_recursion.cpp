#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

void insert(vector<int> &arr, int temp);

void sort_arr(vector<int> &arr) {
  if (arr.size() == 1) { // idx actually represents mutable array size
    return;              // arr is sorted (if there's single element only)
  }
  int temp = arr[arr.size() - 1];
  arr.pop_back();
  sort_arr(arr);
  // now place arr[idx - 1] in correct order
  insert(arr, temp); // induction
}

void insert(vector<int> &arr, int temp) {
  if (arr.size() == 0 || arr[arr.size() - 1] <= temp) {
    arr.push_back(temp);
    return;
  }

  int val = arr[arr.size() - 1];
  arr.pop_back();
  insert(arr, temp);
  arr.push_back(val);
}

int main(void) {
  vector<int> arr{};
  string input{};

  cin >> input;
  string temp{};

  istringstream istream{input};
  while (getline(istream, temp, ',')) {
    arr.emplace_back(stoi(temp));
  }

  sort_arr(arr);
  for (size_t i{}; i < arr.size() - 1; i++) {
    cout << arr[i] << ",";
  }
  cout << arr[arr.size() - 1] << endl;
}
