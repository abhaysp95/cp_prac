// https://leetcode.com/problems/subtree-of-another-tree/description/

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
		bool isSubtree(TreeNode *root, TreeNode *subRoot) {
			if (subRoot == nullptr) return true;
			if (root == nullptr) return false;

			if (root->val == subRoot->val) {
				if (check_if_same_tree(root, subRoot)) {
					return true;
				}
			}

			bool status = isSubtree(root->left, subRoot);
			if (!status) status = isSubtree(root->right, subRoot);

			return status;
		}

		bool check_if_same_tree(TreeNode* root1, TreeNode *root2) {
			if (root1 == nullptr && root2 == nullptr) return true;
			if (root1 == nullptr || root2 == nullptr) return false;

			if (root1->val != root2->val) {
				return false;
			}

			return check_if_same_tree(root1->left, root2->left)
				&& check_if_same_tree(root1->right, root2->right);
		}

		// the solution would've worked if question would've asked, if a given tree
		// (smaller one) is part of the other tree (big one), ie., the small tree can
		// be found anywhere in the big tree (not necessary to start matching up to
		// all its descendant)
		/** Example:
		 * root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
		 * subRoot is part of root tree, but will fail the constraint for the
		 * question here, because 0 also needs to be matched (question says
		 * upto its descendant), this solution just considers that you're
		 * part, not that if start matching match up till leaf */
		bool isSubtree_not_correct_as_per_question(TreeNode *root, TreeNode *subRoot) {
			string in1 = inorder_traversal(root);
			string in2 = inorder_traversal(subRoot);

			if (in1.size() < in2.size())
				return false;

			// check if string in2 is part of string in1
			size_t d = in2.size(), l = 0;
			while ((l + d) <= in1.size()) {
				string substr = in1.substr(l, d);
				if (substr == in2) {
					return true;
				}
				l += 2;
			}

			return false;
		}

		string inorder_traversal(TreeNode* root) {
			if (root == nullptr) return "";

			string l = inorder_traversal(root->left);
			string r = inorder_traversal(root->right);

			return l + to_string(root->val) + "-" + r;
		}
};

/** TODO: do these too
 * https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
 * https://leetcode.com/problems/count-univalue-subtrees/description/
 * https://leetcode.com/problems/most-frequent-subtree-sum/description/
 */
