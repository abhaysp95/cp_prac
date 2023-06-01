// https://leetcode.com/problems/diameter-of-binary-tree/

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
		// idea is to get the height of every node recursively and in
		// induction part of recursion, update the diameter
		int diameterOfBinaryTree(TreeNode *root) {
			// in case some language don't support reference or pointer,
			// you can use global (or class-level max diameter variable) also
			size_t maxd = 0;

			diameter_of_binary_tree(root, maxd);

			return maxd;
		}

		int diameter_of_binary_tree(TreeNode* root, size_t maxd) {
			if (root == nullptr) return 0;

			size_t l = diameter_of_binary_tree(root->left, maxd);
			size_t r = diameter_of_binary_tree(root->right, maxd);

			maxd = max(maxd, l + r);  // update diameter

			return max(l, r) + 1;  // return height
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/tree-diameter/
 * https://leetcode.com/problems/diameter-of-n-ary-tree/description/
 * https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
 */
