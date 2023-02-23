#include <bits/stdc++.h>
#include <sstream>
#include <stack>

using namespace std;

void delete_mid_element_stack_loop(stack<int> &st) {
  size_t mid = (st.size() / 2) + 1;
  stack<int> temp{};

  while (st.size() != mid) {
    temp.emplace(st.top());
    st.pop();
  }

  st.pop();

  while (!temp.empty()) {
    st.emplace(temp.top());
    temp.pop();
  }
}

void delete_mid_element_stack_recursion(stack<int> &st, size_t mid) {
  if (st.size() == mid) {
    st.pop();
    return;
  }

  int val = st.top();
  st.pop();
  delete_mid_element_stack_recursion(st, mid);
  st.emplace(val);
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

  delete_mid_element_stack_loop(st);
  // delete_mid_element_stack_recursion(st, (st.size() / 2) + 1);

  while (!st.empty()) {
    int val = st.top();
    st.pop();
    cout << val << ' ';
  }

  cout << endl;

  return 0;
}
