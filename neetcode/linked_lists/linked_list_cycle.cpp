// https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>

using namespace std;

/** Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		bool hasCycle(ListNode *head) {
			ListNode *sp = head, *fp = head;

			while (fp != nullptr && fp->next != nullptr) {
				sp = sp->next;
				fp = fp->next->next;
				if (sp == fp) {
					return true;
				}
			}

			return false;
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/linked-list-cycle-ii/
 * https://leetcode.com/problems/happy-number/description/
 */
