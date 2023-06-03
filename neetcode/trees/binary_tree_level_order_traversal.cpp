// https://leetcode.com/problems/binary-tree-level-order-traversal/


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
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> res{};
			vector<int> level{};
			if (root == nullptr) return res;
			queue<const TreeNode*> q{};
			q.push(root);
			q.push(nullptr);  // indicates level finished

			while (!q.empty()) {
				const TreeNode* temp = q.front();
				q.pop();

				if (temp == nullptr) {
					res.push_back(level);
					level.clear();
					if (q.empty()) {  // last level
						break;
					}
					q.push(nullptr); // cause every time we reach here, it means
									 // queue already has next levels node
									 // (ie., current levels child, if any)
				}

				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}

			return res;
		}
};


/** TODO: do these too
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 * https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/
 */
