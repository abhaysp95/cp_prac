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
    bool isValidBST(TreeNode* root) {
		// return dfs(root, INT_MIN, INT_MAX);

		// or more easy way
		vector<int> traversed{};
		inorder_traversal(root, traversed);

		for (size_t i = 0; i < traversed.size() - 1; i++) {
			if (traversed[i] >= traversed[i + 1]) {
				return false;
			}
		}

		return true;
	}

	bool dfs(TreeNode* root, int lb, int rb) {
		if (root == nullptr) return true;
		bool ls = dfs(root->left, lb, root->val);
		bool rs = dfs(root->left, root->val, rb);
		if (ls && rs && lb < root->val && rb > root->val) {
			return true;
		}
		return false;
	}

	void inorder_traversal(TreeNode* root, vector<int>& traversed) {
		if (root == nullptr) return;
		inorder_traversal(root->left, traversed);
		traversed.push_back(root->val);
		inorder_traversal(root->right, traversed);
	}
};
