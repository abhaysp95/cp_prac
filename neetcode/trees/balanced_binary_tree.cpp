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
		bool isBalanced(TreeNode* root) {
			bool status = true;

			is_balanced(root, status);

			return status;
		}

		int is_balanced(TreeNode* root, bool& status) {
			if (root == nullptr) return 0;

			size_t l = is_balanced(root->left, status);
			size_t r = is_balanced(root->right, status);

			if (status && (max(l, r) - min(l, r)) > 1) status = false;

			return max(l, r) + 1;
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/invert-binary-tree/
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 * https://leetcode.com/problems/merge-two-binary-trees/description/
 */
