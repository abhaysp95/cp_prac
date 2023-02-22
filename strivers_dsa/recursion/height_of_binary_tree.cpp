#include <bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

node* create_tree() {
	node *root = (node *)malloc(sizeof(node) * 1);
	root->data = 1;

	root->left = (node *)malloc(sizeof(node) * 1);
	root->left->data = 2;
	root->right = (node *)malloc(sizeof(node) * 1);
	root->right->data = 3;

	root->left->left = (node *)malloc(sizeof(node) * 1);
	root->left->left->data = 4;
	root->left->right = (node *)malloc(sizeof(node) * 1);
	root->left->right->data = 5;
	root->right->left = (node *)malloc(sizeof(node) * 1);
	root->right->left->data = 6;

	root->left->right->left = (node *)malloc(sizeof(node) * 1);
	root->left->right->left->data = 7;
	root->right->left->right = (node *)malloc(sizeof(node) * 1);
	root->right->left->right->data = 8;

	root->right->left->right->left = (node *)malloc(sizeof(node) * 1);
	root->right->left->right->left->data = 9;
	root->right->left->right->right = (node *)malloc(sizeof(node) * 1);
	root->right->left->right->right->data = 10;

	root->right->left->right->right->left = (node *)malloc(sizeof(node) * 1);
	root->right->left->right->right->left->data = 11;


	return root;
}

size_t height_of_tree(node *root) {
	// base condition
	if (root == nullptr) return 0;
	// induction + hypothesis
	return 1 + max(height_of_tree(root->left), height_of_tree(root->right));
}

int main(void) {
	node *root = create_tree();

	cout << height_of_tree(root) << endl;

	return 0;
}
