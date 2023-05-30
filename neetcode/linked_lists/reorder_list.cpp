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

		// fails some test cases
		// idea was to move in circular motion, first to last, then last to second, then second to second-last etc.
		void reorderList(ListNode* head) {
			if (head == nullptr || head->next == nullptr) return;

			ListNode *ptr = head, *nptr = head, *tptr = head, *tp = nullptr;

			while (ptr->next != nullptr) {
				cout << "ptr: " << ptr->val << "\n";
				nptr = ptr->next;
				// get tptr
				while (tptr->next != nullptr) {
					cout << "tptr: " << tptr->val << "\n";
					if (tptr->next->next == nullptr) {
						cout << "inside if" << "\n";
						tp = tptr;
						tptr = tptr->next;
						tp->next = nullptr;
						break;
					}
					tptr = tptr->next;
				}
				ptr->next = tptr;
				// if (tptr->val != nptr->val) { // condition will fail on non-unique elements linked list
				if (tptr != nptr) {  // handle connection in case length is even
					tptr->next = nptr;
				}
				ptr = nptr;
				tptr = ptr;
			}
		}

		// idea is to divide the list in 2 parts (half), second-half should be reversed, then merge the list one-by-one
		void reorderList2(ListNode* head) {
			// no point in going forward if list.size() <= 2
			if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return;

			// two-pointer method to get half of list
			ListNode *sf = head, *ff = head->next;

			while (ff != nullptr && ff->next != nullptr) {
				sf = sf->next;
				ff = ff->next->next;
			}

			// we have to make sf->next = nullptr and then reverse the list
			ListNode *pptr = nullptr, *ptr = sf->next, *nptr = ptr;
			sf->next = nullptr;  // ptr already points to the next
			// make the list reverse
			while (ptr != nullptr) {
				nptr = ptr->next;
				ptr->next = pptr;
				pptr = ptr;
				ptr = nptr;
			}
			// now pptr points to the start of reversed list

			// merge the lists
			ListNode *l1 = head, *l2 = pptr;
			// NOTE: l1.size() >= l2.size()  (becase we are doing
			// "ptr = sf->next; sf->next = nullptr;" not
			// "prev_sf->next = nullptr; ptr = sf;" in which case,
			// l1.size() <= l2.size())
			while (l2 != nullptr) {
				ListNode *nl1 = l1->next, *nl2 = l2->next;
				l1->next = l2;
				l2->next = nl1;
				l1 = nl1;
				l2 = nl2;
			}
			/** in case of l1.size() <= l2.size() */
			/* while (l1 != nullptr) {
				ListNode *nl1 = l1->next, *nl2 = l2->next;
				l1->next = l2;
				if (nl1 != nullptr) l2->next = nl1;
				l1 = nl1;
				l2 = nl2;
			} */
		}
};

