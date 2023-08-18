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

void all_strings(string& s, int idx, set<string>& arr) {
	arr.insert(s);

	for (int i = idx; i < sz(s); i++) {
		swap(s[i], s[idx]);
		all_strings(s, idx + 1, arr);
		swap(s[i], s[idx]);
	}
}

void solve_extraspace() {
	string s{};
	cin >> s;

	set<string> arr{};
	all_strings(s, 0, arr);

	cout << arr.size() << '\n';
	for (const string& s: arr) {
		cout << s << '\n';
	}
}

int char_count[26];

// generates permutation for string in lexographical order
void gen_permute(const string& s, vector<string>& perm, const string& curr = "") {
	if (sz(s) == sz(curr)) {
		perm.push_back(curr);
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (char_count[i]) {
			char_count[i]--;
			gen_permute(s, perm, curr + (char)('a' + i));
			char_count[i]++;
		}
	}
}

// constant space
void solve() {
	memset(char_count, 0, sizeof(char_count));
	string s{};
	cin >> s;

	for (const char c: s) {
		char_count[c - 'a']++;
	}

	vector<string> perm{};

	gen_permute(s, perm);
	cout << sz(perm) << '\n';
	for (const string& s: perm) cout << s << '\n';
}

// if you're going to use std::next_permutation(), remember to sort the
// container(arr/string) before calling next_permutation() as this method
// generates permutation in lexographical order

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cerr.tie(nullptr);

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

