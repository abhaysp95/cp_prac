#include <bits/stdc++.h>

using namespace std;

class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> res{};
			this->all_permutation(0, nums, res);

			return res;
		}

		ostream& print_arr2d(ostream& out, const vector<vector<int>>& arr2d) {
			out << '[';
			if (!arr2d.empty()) {
				for (const vector<int>& arr: arr2d) {
					this->print_arr(out, arr);
				}
			}
			out << ']';

			return out;
		}

		ostream& print_arr(ostream& out, const vector<int>& arr) {
			out << '[';
			if (!arr.empty()) {
				for (size_t i{}; i < arr.size() - 1; i++) {
					out << arr[i] << ",";
				}
				out << arr[arr.size() - 1];
			}
			out << ']';

			return out;
		}

	private:
		void all_permutation(size_t idx, vector<int>& nums, vector<vector<int>>& res) {
			if (nums.size() == idx) {
				res.emplace_back(nums);
				return;
			}

			for (size_t i{idx}; i < nums.size(); i++) {
				swap(nums[i], nums[idx]);
				all_permutation(idx + 1, nums, res);  // call with idx, because subsets are n!
				swap(nums[i], nums[idx]);
			}
		}

};

int main(void) {
	vector<int> arr{};
	string input{};

	cin >> input;
	if (!input.empty() && input[0] == '[') {  // a simple check (which obviously can fail)
		input = input.substr(1, input.size() - 2);
	}

	istringstream istream{input};
	string temp{};
	while (getline(istream, temp, ',')) {
		arr.emplace_back(stoi(temp));
	}

	Solution solve{};
	vector<vector<int>> res = solve.permute(arr);
	solve.print_arr2d(cout, res) << endl;

	return 0;
}
