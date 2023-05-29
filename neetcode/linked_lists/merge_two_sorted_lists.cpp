#include <bits/stdc++.h>

using namespace std;

/** Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(), *tail = head;

		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		if (l1 != nullptr) {
			tail->next = l1;
		}
		if (l2 != nullptr) {
			tail->next = l2;
		}

		return head->next;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr && l2 == nullptr) return nullptr;
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode *head = nullptr, *tail = head;

		if (l1->val < l2->val) {
			head =l1;
			l1 = l1->next;
		} else {
			head = l2;
			l2 = l2->next;
		}
		tail = head;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			} else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		if (l1 != nullptr) {
			tail->next = l1;
		}
		if (l2 != nullptr) {
			tail->next = l2;
		}

		return head;
    }
};

/** TODO: do these too
 * https://leetcode.com/problems/sort-list/description/
 * https://leetcode.com/problems/shortest-word-distance-ii/description/
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 */
