#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    int arr[100000];
	int cur_min;
    int minarr[100000];
    size_t idx = 0;
public:
    MinStack() {
        memset(this->arr, 0, sizeof(this->arr));
		cur_min = INT_MAX;
    }

    void push(int val) {
        this->arr[idx] = val;
		cur_min = min(cur_min, this->arr[idx]);
		this->minarr[idx] = cur_min;
        /* if (this->idx == 0) {
            this->minarr[idx] = val;
        } else {
            this->minarr[idx] = min(val, this->minarr[idx - 1]);
        } */
        this->idx++;
    }

    void pop() {
        if (this->idx != 0) {
            this->idx--;
        }
    }

    int top() {
        // top will always be called on non-empty stack (says the question)
        return this->arr[idx - 1];
    }

    int getMin() {
        return this->minarr[idx - 1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// NOTE: also do
// https://leetcode.com/problems/max-stack/
// https://leetcode.com/problems/sliding-window-maximum/description/
