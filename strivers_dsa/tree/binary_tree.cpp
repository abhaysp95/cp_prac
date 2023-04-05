#include <bits/stdc++.h>
#include <memory>
#include <queue>
#include <random>
#include <stack>

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
	root->left->left = new Node(6);
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

// it's dfs traversal, but right child goes first in stack before left one
void preorder_traversal_iterative(const Node* root) {
	if (nullptr == root) return;

	stack<const Node*> stk{};
	stk.push(root);

	while (!stk.empty()) {
		auto my_node = stk.top();
		stk.pop();
		cout << my_node->value << " ";

		if (my_node->right != nullptr) stk.push(my_node->right);
		if (my_node->left != nullptr) stk.push(my_node->left);
	}
}

void inorder_traversal_iterative(const Node *root) {
	if (nullptr == root) return;

	stack<const Node*> stk{};

	while (true) {
		if (nullptr != root) {
			stk.push(root);
			root = root->left;
		} else {
			if (stk.empty()) break;
			const Node* parent = stk.top();
			stk.pop();
			cout << parent->value << " ";
			root = parent->right;
		}
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
	cout << "\n----------------\n";
	preorder_traversal_iterative(root);
	cout << "\n----------------\n";
	inorder_traversal_iterative(root);

	return 0;
}
