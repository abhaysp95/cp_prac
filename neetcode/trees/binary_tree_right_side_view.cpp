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
		vector<int> rightSideView(TreeNode* root) {
			vector<int> res{};
			if (root == nullptr) return res;
			queue<const TreeNode*> q{};
			q.push(root);

			while (!q.empty()) {
				size_t qsize = q.size();

				while (qsize > 0) {  // ie., run for one whole level
					const TreeNode* temp = q.front();
					q.pop();

					if (qsize == 1) {  // this is the rightmost node of level
						res.push_back(temp->val);
					}

					if (temp->left) q.push(temp->left);
					if (temp->right) q.push(temp->right);

					qsize--;
				}
			}

			return res;
		}
};


/** TODO: do these too
 * https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
 * https://leetcode.com/problems/boundary-of-binary-tree/description/
 */
