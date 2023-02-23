#include <algorithm>
#include <bits/stdc++.h>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

void insert(stack<int> &st, int temp);

void sort_stack(stack<int> &st) {
  if (st.size() == 1)
    return;

  int temp = st.top();
  st.pop();
  sort_stack(st);
  insert(st, temp);
}

void insert(stack<int> &st, int temp) {
  if (st.empty() || st.top() >= temp) {
    st.push(temp);
    return;
  }

  int val = st.top();
  st.pop();
  insert(st, temp);
  st.push(val);
}

int main(void) {
  stack<int> st{};
  string input{};

  cin >> input;
  string temp{};

  istringstream istream{input};

  while (getline(istream, temp, ',')) {
    st.emplace(stoi(temp));
  }

  sort_stack(st);

  while (!st.empty()) {
	  cout << st.top() << " ";
	  st.pop();
  }
  cout << endl;

  return 0;
}
