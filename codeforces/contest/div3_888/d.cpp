#include <bits/stdc++.h>
#include <ios>

using namespace std;

#define sz(a) (int)(a.size())
#define ll long long

inline ll nxt() {
	ll x;
	cin >> x;
	return x;
}

// not passing all example test cases (will fix this)
bool solve() {
	int n = nxt();
	vector<ll> presum(n - 1);
	for (int i = 0; i < n - 1; i++) presum[i] = nxt();

	map<ll, bool> appear{};
	for (int i = 0; i < n; i++) appear[i] = false;

	ll mdiff = -1;
	for (int i = 0 ; i < sz(presum) - 1; i++) {
		ll diff = presum[i + 1] - presum[i];
		if (appear.find(diff) == appear.end()) {
			if (mdiff != -1) return false;
			mdiff = diff;
		}
		appear[diff] = true;
	}

	ll first = -1, second = -1;
	for (const pair<const ll, bool>& p: appear) {
		if (!p.second) {
			if (first == -1) first = p.first;
			else if (second == -1) second = p.first;
		}
		if (first != -1 && second != -1) break;
	}

	if (mdiff != -1) {  // if some middle element is missing from prefix sum
		return first + second == mdiff;
	}

	// mdiff is not the possibility
	if (first + second == presum[0]) {  // if first in presum is missing
		return true;
	}

	ll tsum = ((ll)n * (1 + (ll)n)) / 2;
	if (first + presum[sz(presum) - 1] == tsum
			|| second + presum[sz(presum) - 1] == tsum) return true;

	return false;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T = nxt();
	while (T--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

	return 0;
}
