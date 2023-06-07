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
		int kthSmallest(TreeNode* root, int k) {
			vector<int> traversed{};

			// since this is BST, doing simple inorder travsel will give us tree in sorted order
			inorder(root, traversed);

			return traversed[traversed.size() - k - 2];
		}

		void inorder(TreeNode *root, vector<int>& traversed) {
			if (root == nullptr) return;
			inorder(root->left, traversed);
			traversed.push_back(root->val);
			inorder(root->right, traversed);
		}

		// solving with iterative inorder traversal */
		int kthSmallest2(TreeNode* root, int k) {
			if (root == NULL) return -1;
			stack<TreeNode*> st{};
			st.push(root);

			TreeNode* cur = root->left;
			while (!st.empty()) {
				while (cur != NULL) {
					st.push(cur);
					cur = cur->left;
				}
				cur = st.top();
				if (--k == 0) {
					return cur->val;
				}
				cur = cur->right;
			}

			return -1;  // shouldn't reach here (as per question constraint)
		}

		/* int kthSmallest(TreeNode* root, int k) {
		   int count{1}, res{};
		   if(nullptr == root) return res;
		   get_element(root, k, count, res);
		   return res;

		   }

		   void get_element(TreeNode* root, int k, int& count, int& res) {
		   if(root == nullptr) return;
		   get_element(root->left, k, count, res);
		   if(count++ == k) res = root->val;
		   get_element(root->right, k, count, res); */

};
