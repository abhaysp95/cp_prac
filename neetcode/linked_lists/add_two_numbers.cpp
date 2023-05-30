// https://leetcode.com/problems/add-two-numbers/submissions/539858097/

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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode *head = new ListNode(), *ptr = head;
			size_t carry = 0;

			while (l1 != nullptr && l2 != nullptr) {
				int sum = carry + l1->val + l2->val;
				ListNode *new_node = new ListNode(sum % 10);
				carry = sum / 10;
				ptr->next = new_node;
				ptr = new_node;
				l1 = l1->next;
				l2 = l2->next;
			}

			// check if any list not fully traversed yet
			while (l1 != nullptr) {
				int sum = carry + l1->val;
				ListNode *new_node = new ListNode(sum % 10);
				carry = sum / 10;
				ptr->next = new_node;
				ptr = new_node;
				l1 = l1->next;
			}
			while (l2 != nullptr) {
				int sum = carry + l2->val;
				ListNode *new_node = new ListNode(sum % 10);
				carry = sum / 10;
				ptr->next = new_node;
				ptr = new_node;
				l2 = l2->next;
			}

			// if carry is left
			if (carry != 0) {
				ListNode *new_node = new ListNode(carry);
				ptr->next = new_node;
			}

			return head->next;
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * https://leetcode.com/problems/multiply-strings/description/
 * https://leetcode.com/problems/add-binary/description/
 * https://leetcode.com/problems/sum-of-two-integers/description/
 */
