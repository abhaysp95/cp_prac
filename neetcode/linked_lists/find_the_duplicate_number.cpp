#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// the approach uses O(n) space (not constant space, which is the constraint)
    int findDuplicate(vector<int>& nums) {
        // wouldn't work if repeated element can occur more than twice

        // size_t sum = accumulate(nums.begin(), nums.end(), 0);

        // size_t expected = ((nums.size() - 1) * (2 + nums.size() - 2)) / 2;

        // return sum - expected;

        vector<int> arr(nums.size(), 0);

        for (size_t i = 0; i < nums.size(); i++) {
            if (arr[nums[i]] != 0) {
                return nums[i];
            }
            arr[nums[i]]++;
        }

        return 0;  // shouldn't reach here (as per constraints)
    }

    // this approach thinks of the given vector as linked list, where index is
    // the value of node and node->next is what the nums[idx], using this we
    // would get to intersection point of slow and fast pointer and then apply
    // floyd's algo
    // (as per the question, there will always be atleast one duplicate element
    // (ie., >= count of 2) and this approach depends on this intuition
	// also, index 0 will never be part of the cycle (and thus only floyd's algo works probably)
    int findDuplicate_constant_space(vector<int>& nums) {
		size_t sp = 0, fp = 0;

		while (1) {
			sp = nums[sp];  // sp = sp->next;
			fp = nums[nums[fp]];  // fp = fp->next->next;
			if (sp == fp) {
				break;
			}
		}

		size_t sp2 = 0;
		while (1) {
			sp2 = nums[sp2];
			sp = nums[sp];
			if (sp2 == sp) {
				return sp;
			}
		}

		return sp;
	}
};

/**
 * Floyd's Algorigthm
 * Consider the cycle in the list be of C size, and the distance between start
 * of the cycle node and intersection of sp (slow pointer) & fp (fast pointer)
 * be X and the distance between start of list and start of cycle (node) is P
 *
 * Thus, the distance covered by sp is: P + (C - X)
 * For the same variables, distance covered by fast pointer would be: P + C + (C X) => P + 2C - X
 *
 * We know, 2 * sp = fp
 *
 * Thus, 2(P + (C - X)) = P + 2C - X => P = X
 *
 * Which proves, that distance between start of list and start of cyle
 * node will be same to distance between start of cycle node and instersection
 * node of sp & fp
 */

/** TODO: do these too
 * https://leetcode.com/problems/find-duplicate-subtrees/
 * https://leetcode.com/problems/first-missing-positive/description/
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 * https://leetcode.com/problems/missing-number/description/
 */
