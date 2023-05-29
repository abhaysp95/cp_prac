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
    #define LN ListNode
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* pptr = NULL, *ptr = head, *nptr = head->next;
        while (ptr != NULL) {
            ptr->next = pptr;
            pptr = ptr;
            ptr = nptr;
            if (nptr != NULL) nptr = nptr->next;
        }

        return pptr;
    }
};

/** TODO: do these too
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 * https://leetcode.com/problems/binary-tree-upside-down/description/
 * https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/
 */
