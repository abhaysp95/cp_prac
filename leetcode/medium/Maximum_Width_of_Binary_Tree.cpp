// https://leetcode.com/problems/maximum-width-of-binary-tree/
#include <bits/stdc++.h>

using namespace std;

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
		// intuition:
		// at each level, right-most node's index - left node's index (from the root) + 1
		// update the max on each level
		// obviously, going with level-order-traversal
		int width_of_binary_tree(TreeNode* root) {
			size_t width{};
			queue<pair<const TreeNode*, size_t>> q{};
			q.push({root, 0});

			while (!q.empty()) {
				size_t qsize = q.size() + 1;

				// left most child index
				size_t lidx = q.front().second;
				while (1 < qsize) {
					if (2 == qsize) {  // last node of level
						size_t ridx = q.front().second;
						width = max(width, ridx - lidx + 1);
					}

					auto cpair = q.front();
					q.pop();
					const TreeNode* cnode = cpair.first;
					size_t cidx = cpair.second;

					if (nullptr != cnode->left) {
						q.push({cnode->left, 2 * cidx + 1});
					}
					if (nullptr != cnode->right) {
						q.push({cnode->right, 2 * cidx + 2});
					}

					qsize--;
				}
			}

			return width;
		}
};
