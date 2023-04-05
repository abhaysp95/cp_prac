#include <bits/stdc++.h>
#include <memory>
#include <queue>
#include <random>

using namespace std;

typedef struct _node {
	int value;
	struct _node *left;
	struct _node *right;

	_node(int value) {
		this->value = value;
	}
} Node;

void add_few_node(Node* &root) {
	root = new Node(10);
	root->left = new Node(7);
	root->right = new Node(11);
	root->left->right = new Node(8);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(9);
	root->right->right = new Node(14);
	root->right->right->left = new Node(13);
	root->right->right->right = new Node(16);
}

void preorder_traversal_recursive(const Node* root) {
	if (nullptr == root) {
		return;
	}

	cout << root->value << " ";
	preorder_traversal_recursive(root->left);
	preorder_traversal_recursive(root->right);
}

int main(void) {
	Node *root = nullptr;
	add_few_node(root);

	return 0;
}
