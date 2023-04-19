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
		int longestZigZag(TreeNode* root) {
			if (nullptr == root) return 0;

			get_longest_zig_zag_path_global_pathlength(root, true, 0);
			get_longest_zig_zag_path_global_pathlength(root, false, 0);
			return this->path_length;

			/* return max(get_longest_zig_zag_path_return_pathlength(root, true),
			get_longest_zig_zag_path_return_pathlength(root, false)) - 1; */
		}

	private:
		size_t path_length;

		size_t get_longest_zig_zag_path_return_pathlength(TreeNode* root, bool move_to_right) {
			if (nullptr == root) {
				return 0;
			}

			size_t ls = get_longest_zig_zag_path_return_pathlength(root->left, true);
			size_t rs = get_longest_zig_zag_path_return_pathlength(root->right, false);

			size_t res;
			if (move_to_right) {  // I'm the left child
				res = max(ls, rs + 1);
			} else {
				res = max(ls + 1, rs);
			}

			return res;
		}

		void get_longest_zig_zag_path_global_pathlength(TreeNode* root, bool move_to_right, size_t count) {
			if (nullptr == root) {
				return;
			}

			path_length = max(path_length, count);
			if (move_to_right) {  // came from left side
				get_longest_zig_zag_path_global_pathlength(root->left, true, 1);
				get_longest_zig_zag_path_global_pathlength(root->right, false, count + 1);  // zig-zag
			} else {  // came from right side
				get_longest_zig_zag_path_global_pathlength(root->left, true, count + 1);  // zig-zag
				get_longest_zig_zag_path_global_pathlength(root->right, false, 1);
			}
		}
};

int main(void) {

	struct TreeNode* root = new TreeNode(1);
	/* root->right = new TreeNode(1);
	root->right->left = new TreeNode(1);
	root->right->right = new TreeNode(1);
	root->right->right->left = new TreeNode(1);
	root->right->right->right = new TreeNode(1);
	root->right->right->left->right = new TreeNode(1);
	root->right->right->left->right->right = new TreeNode(1); */

	root->left = new TreeNode(1);
	root->right = new TreeNode(1);
	root->left->right = new TreeNode(1);
	root->left->right->right = new TreeNode(1);
	root->left->right->left = new TreeNode(1);
	root->left->right->left->right = new TreeNode(1);

	Solution sol{};
	cout << sol.longestZigZag(root) << endl;

	return 0;
}
