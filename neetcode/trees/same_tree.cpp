#include <bits/stdc++.h>

using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
		bool isSameTree(TreeNode* p, TreeNode* q) {
			if (p == nullptr && q == nullptr) return true;
			if (p == nullptr || q == nullptr) return false;

			if (p->val != q->val) return false;

			return isSameTree(p->left, q->left)
				&& isSameTree(p->right, q->right);
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/description/
 * https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/description/
 * https://leetcode.com/problems/max-area-of-island/description/
 */
