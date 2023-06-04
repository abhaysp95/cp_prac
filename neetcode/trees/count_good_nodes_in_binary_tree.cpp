// https://leetcode.com/problems/binary-tree-right-side-view/

#include <bits/stdc++.h>

using namespace std;

/** Definition for a binary tree node. */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int goodNodes(TreeNode* root) {
			if (root == nullptr) return 0;
			size_t gn = 1;
			count_good_nodes(root, gn, root->val);

			return gn;
		}

		void count_good_nodes(TreeNode *root, size_t& gn, int maxp) {
			if (root == nullptr) return;
			if (root->left) {
				if(root->left->val >= maxp) gn++;
				count_good_nodes(root->left, gn, max(maxp, root->left->val));
			}
			if (root->right) {
				if (root->right->val >= maxp) gn++;
				count_good_nodes(root->right, gn, max(maxp, root->right->val));
			}
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/count-good-triplets-in-an-array/
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 * https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
 * https://leetcode.com/problems/inorder-successor-in-bst-ii/description/
 */
