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
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			// get size of list
			size_t sz = 0;
			ListNode *pptr = nullptr, *ptr = head;

			while (ptr != nullptr) {
				ptr = ptr->next;
				sz++;
			}

			// get to the nth node
			ptr = head;
			size_t k = 0;
			while (k++ < (sz - n)) {
				pptr = ptr;
				ptr = ptr->next;
			}

			if (pptr == nullptr) {  // ie., sz - n == 0, means remove the first element
				return ptr->next;  // return second node from start
			}
			pptr->next = ptr->next;

			return head;
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/remove-nodes-from-linked-list/
 * https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/description/
 * https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
 * https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
 */
