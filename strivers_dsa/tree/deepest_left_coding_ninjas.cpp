#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BinaryTreeNode
{
	public:
		T data;
		BinaryTreeNode<T> *left;
		BinaryTreeNode<T> *right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

pair<int, int> traverse(BinaryTreeNode<int>*, int);

int deepestLeftLeafNode(BinaryTreeNode<int>* root)
{
	if (root == nullptr) return -1;
	if (root->left == nullptr && root->right == nullptr) return 0;
	pair<int, int> result = traverse(root, -1);

	return result.first;
}

/**
 * @param: dir => -1 (root node), 1 (left child), 2 (right child)
 */
pair<int, int> traverse(BinaryTreeNode<int>* root, int dir) {
	if (root->left == nullptr && root->right == nullptr) {
		return dir ==  1 ? make_pair(root->data, 0) : make_pair(-1, 0);
	}

	pair<int, int> left{-1, -1}, right{-1, -1};
	if (root->left != nullptr) {
		left = traverse(root->left, 1);
	}
	if (root->right != nullptr) {
		right = traverse(root->right, 2);
	}

	if (left.first == -1 && right.first == -1) {
		return {-1, max(left.second, right.second)};
	} else if (left.first == -1) {
		return {right.first, right.second + 1};
	} else if (right.first == -1) {
		return {left.first, left.first + 1};
	} else {
		if (left.second == right.second) return {max(left.first, right.first), left.second + 1};
		else if (left.second > right.second)  return {left.first, left.second + 1};
		else return {right.first, right.second + 1};
	}
}
