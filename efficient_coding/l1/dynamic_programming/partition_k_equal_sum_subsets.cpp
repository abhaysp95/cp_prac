#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using vvec = vector<vector<int>>;
using vec = vector<int>;

bool is_equal_subset(const vec& nums, size_t rbucket, size_t cbucket, int rtarget, vector<bool>& is_avail, size_t idx, int target, vvec& space) {
	if (cbucket == rbucket) {
		return true;
	}
	if (target == 0) {
		return is_equal_subset(nums, rbucket, cbucket + 1, rtarget, is_avail, 0, rtarget, space);
	}
	if (idx == nums.size()) {
		return false;
	}

	if (!is_avail[idx]) {
		return is_equal_subset(nums, rbucket, cbucket, rtarget, is_avail, idx + 1, target, space);
	}

	if (space[idx][target] != -1) {
		return space[idx][target] == 1 ? true : false ;
	}

	bool res{};
	if (target >= nums[idx]) {
		is_avail[idx] = false;
		res = is_equal_subset(nums, rbucket, cbucket, rtarget, is_avail, idx + 1, target - nums[idx], space);
	}
	is_avail[idx] = true;
	res |= is_equal_subset(nums, rbucket, cbucket, rtarget, is_avail, idx + 1, target, space);

	space[idx][target] = res ? 1 : 0;
	return res;
}

int main(void) {
	size_t T{};
	cin >> T;

	while (T--) {
		size_t N{}, K{};
		cin >> N >> K;

		string input{};
		cin >> input;
		istringstream isstream{input};
		string temp{};
		vec nums{};
		while (getline(isstream, temp, ',')) {
			nums.push_back(stoi(temp));
		}

		size_t sum = accumulate(nums.begin(), nums.end(), 0);
		vvec space(N + 1, vec((sum / K) + 1, -1));
		vector<bool> is_avail(N, true);
		cout << (sum % K == 0
				? (is_equal_subset(nums, K, 0, sum / K, is_avail, 0, sum / K, space) ? "Yes" : "No")
				: "No") << endl;

	}
	return 0;
}

/**
 * Test case (just one time)
 * arr_size, bucket_size
 * numbers
 *
 * 3
 * *************************
 * 5 3
 * 4,1,5,6,2
 * *************************
 * 5 3
 * 5,1,2,5,6
 * *************************
 * 8 3
 * 4,3,1,3,4,3,1,2
 */
