#include <bits/stdc++.h>

using namespace std;

class KthLargest {
	private:
		// making of min-heap in C++
		priority_queue<int, vector<int>, greater<int>> minheap{};
		int k = 0;
	public:
		KthLargest(int k, vector<int>& nums) {
			this->k = k;
			for (const int x: nums) {
				minheap.push(x);
			}

			size_t sz = minheap.size();
			while (sz > k) {
				minheap.pop();
				sz--;
			}
		}

		int add(int val) {
			this->minheap.push(val);

			if (minheap.size() > this->k) {
				minheap.pop();
			}

			return minheap.top();
		}
};

class KthLargest_brute_force {
private:
    vector<int> nums;
    int k;

	// the solution will certainly work but is not very space efficient and (time effiecient too)
public:
    KthLargest_brute_force(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;

        sort(this->nums.begin(), this->nums.end());

    }

    int add_brute_force(int val) {
        size_t start = 0, end = this->nums.size();
        vector<int> temp(this->nums.size() + 1, 0);

		// find out the position to where to insert new element
        while (start < end) {
            size_t mid = start + ((end - start) / 2);
            if (this->nums[mid] < val) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        // right now, start == end
        size_t k = 0;
        for (size_t i = 0; i < start; i++, k++) {
            temp[k] = this->nums[i];
        }
        temp[k++] = val;
        for (size_t i = start; i < this->nums.size(); i++, k++) {
            temp[k] = this->nums[i];
        }

        this->nums = temp;
        // print_arr(this->nums);
        return this->nums[this->nums.size() - this->k];
    }

    void print_arr(const vector<int>& arr) {
        for (int x: arr) {
            cout << x << " ";
        }
        cout << endl;
    }

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
