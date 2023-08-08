#include <bits/stdc++.h>
#include <climits>

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
public:
    int minimumSeconds(vector<int>& nums) {
		map<int, vector<int>> mp{};
		int n = (int)nums.size();
		for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);

		int mtime = INT_MAX;
		for (const pair<const int, vector<int>>& p: mp) {
			int time = 0;
			int icount = (int)p.second.size();
			int start = p.second[0];
			int end = p.second[icount - 1];
			time = max(time, (n - (end - start + 1) + 1) / 2);
			for (int i = 1; i < icount; i++) {
				time = max(time, (p.second[i] - p.second[i - 1]) / 2);
			}
			mtime = min(mtime, time);
		}

		return mtime;
	}

	// correct, but will give TLE
    int minimumSeconds_bruteforce(vector<int>& nums) {
		set<int> s{};
		for (const int x: nums) s.insert(x);
		int n = (int)nums.size();

		if (s.size() == 1) return 0;

		int mtime = INT_MAX;
		for (const int x: s) {
			vector<int> temp = nums;
			int time = 0;
			while(true) {  // refers each pass
				vector<int> idxs{};
				for (int i = 0; i < n; i++) if(temp[i] == x) idxs.push_back(i);

				for (const int i: idxs) {
					if (temp[i] == x) {
						temp[(i - 1 + n) % n] = x;
						temp[(i + 1) % n] = x;
					}
				}
				time++;
				bool stat = true;
				for (int i = 1; i < n; i++) if(temp[i - 1] != temp[i]) stat = false;
				if (stat) break;
			}
			mtime = min(mtime, time);
		}

		return mtime;
    }
};

void solve() {
	string input{};
	cin >> input;
	input = input.substr(1, input.size() - 2);
	istringstream istream{input};
	string s{};
	vector<int> nums{};
	while (getline(istream, s, ',')) {
		nums.push_back(stoi(s));
	}

	Solution solve{};
	cout << solve.minimumSeconds(nums) << '\n';
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

