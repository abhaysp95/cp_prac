#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

class Solution {
	unordered_map<string, bool> umap{};
	public:
		bool canSplitArray(vector<int>& nums, int m) {
			int sum = accumulate(all(nums), 0);
			return can_split(nums, m, sum, 0, nums.size() - 1);
		}

		bool can_split(const vector<int>& nums, int m, int sum, int start, int end) {
			if (end - start + 1 <= 2) return true;

			string key = to_string(sum) + "-" + to_string(start) + "-" + to_string(end);
			if (umap.find(key) != umap.end()) return umap[key];

			bool stat = false;
			int new_sum = sum - nums[start];
			if (new_sum >= m) {
				stat |= can_split(nums, m, new_sum, start + 1, end);
			}
			new_sum = sum - nums[end];
			if (new_sum >= m) {
				stat |= can_split(nums, m, new_sum, start, end - 1);
			}

			return umap[key] = stat;
		}
};

void solve() {
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cerr.tie(nullptr);

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

