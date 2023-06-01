// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
		int maxDepth(TreeNode* root) {
			if (root == nullptr) return 0;

			return max(maxDepth(root->left), maxDepth(root->right)) + 1;
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/palindrome-linked-list/
 * https://leetcode.com/problems/balanced-binary-tree/description/
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 * https://leetcode.com/problems/maximum-depth-of-n-ary-tree/description/
 */
