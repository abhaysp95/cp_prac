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

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode* insertGreatestCommonDivisors(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return head;

			ListNode *ptr = head, *nptr = head->next;
			while (nptr != nullptr) {
				ListNode *new_node = new ListNode(gcd(ptr->val, nptr->val));
				ptr->next = new_node;
				new_node->next = nptr;
				ptr = nptr;
				nptr = nptr->next;
			}

			return head;
		}

		int gcd(int x, int y) {
			while (x != y) {
				if (x > y) x -= y;
				else y -= x;
			}

			return x;
		}
};

void solve() {
	/* Solution solve{};
	solve.insertGreatestCommonDivisors(nullptr); */
}

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

