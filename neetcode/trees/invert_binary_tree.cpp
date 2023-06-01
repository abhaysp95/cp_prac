// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode *invertTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}

		TreeNode *new_node = new TreeNode(root->val);
		new_node->right = invertTree(root->left);
		new_node->left = invertTree(root->right);

		return new_node;
	}
};

/** TODO: do these too
 * https://leetcode.com/problems/balanced-binary-tree/
 * https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/description/
 */
