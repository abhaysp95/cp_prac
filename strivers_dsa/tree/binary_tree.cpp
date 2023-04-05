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

void inorder_traversal_recursive(const Node* root) {
	if (nullptr == root) {
		return;
	}

	inorder_traversal_recursive(root->left);
	cout << root->value << " ";
	inorder_traversal_recursive(root->right);
}

void postorder_traversal_recursive(const Node* root) {
	if (nullptr == root) {
		return;
	}

	postorder_traversal_recursive(root->left);
	postorder_traversal_recursive(root->right);
	cout << root->value << " ";
}

void levelorder_traversal(const Node* root) {
	queue<const Node*> q{};
	if (nullptr == root) return;
	q.push(root);

	while (!q.empty()) {
		const Node* my_node = q.front();
		cout << my_node->value << " ";
		q.pop();

		if (nullptr != my_node->left) q.push(my_node->left);
		if (nullptr != my_node->right) q.push(my_node->right);
	}
}

int main(void) {
	Node *root = nullptr;
	add_few_node(root);

	preorder_traversal_recursive(root);
	cout << "\n----------------\n";
	inorder_traversal_recursive(root);
	cout << "\n----------------\n";
	postorder_traversal_recursive(root);
	cout << "\n----------------\n";
	levelorder_traversal(root);

	return 0;
}
