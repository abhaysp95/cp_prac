#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
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

void postorder_traversal_iterative_2stack(const Node *root) {
	if (nullptr == root) return;

	stack<const Node*> stk{};
	stack<const Node*> print_stk{};
	stk.push(root);

	while (!stk.empty()) {
		const Node* curr_node = stk.top();
		stk.pop();
		print_stk.push(curr_node);

		if (nullptr != curr_node->left) stk.push(curr_node->left);
		if (nullptr != curr_node->right) stk.push(curr_node->right);
	}

	while (!print_stk.empty()) {
		cout << print_stk.top()->value << " ";
		print_stk.pop();
	}
}

void postorder_traversal_iterative_single_stack(const Node *root) {
	stack<const Node*> stk{};

	while (nullptr != root || !stk.empty()) {
		if (nullptr != root) {
			stk.push(root);
			root = root->left;
		} else {  // root has no left child
			if (nullptr == stk.top()->right) {  // if root has no right child
				// print the parent now (because left & right of a parent is done now)
				const Node *parent = stk.top();
				stk.pop();
				cout << parent->value << " ";
				// if the parent was the right child then you've to print it's parent too
				// until either stack is empty or the parent becomes it's parent's left child
				while (!stk.empty() && parent == stk.top()->right) {
					parent = stk.top();
					cout << stk.top()->value << " ";
					stk.pop();
				}
			} else {  // root has right child, make it current root
				root = stk.top()->right;
			}
		}
	}
}

/**
 * preorder, inorder & postorder traversal in one go
 * rules:
 * ptr.second == 1 => pop() after getting top(). print(top.value()).
 * push(top().second++). push(if (NULL != top()->left))
 *
 * ptr.second == 2 => pop() after getting top(). print(top.value()).
 * push(top().second++). push(if (NULL != top()->right))
 *
 * ptr.second == 3 => pop() after getting top(). print(top.value()).
 */
void trio_traversal_iterative(const Node *root) {
	if (nullptr == root) return;

	stack<pair<const Node*, size_t>> stk{};
	stk.push({root, 1});

	vector<int> pre{}, in{}, post{};

	while (!stk.empty()) {
		auto curr_pair = stk.top();
		stk.pop();
		if (1 == curr_pair.second) {
			stk.push({curr_pair.first, curr_pair.second + 1});
			pre.push_back(curr_pair.first->value);
			if (nullptr != curr_pair.first->left) {
				stk.push({curr_pair.first->left, 1});
			}
		} else if (2 == curr_pair.second) {
			stk.push({curr_pair.first, curr_pair.second + 1});
			in.push_back(curr_pair.first->value);
			if (nullptr != curr_pair.first->right) {
				stk.push({curr_pair.first->right, 1});
			}
		} else {
			post.push_back(curr_pair.first->value);
		}
	}
	cout << "preorder  inorder  postorder" << '\n';
	for (size_t i{}; i < pre.size(); i++) {
		cout << setw(5) << right << pre[i]
			<< setw(9) << right << in[i]
			<< setw(9) << right << post[i] << '\n';
	}
}

// maximum depth/height of tree (number of max edges in a path + 1)
size_t tree_depth_recursive(const Node *root) {
	if (nullptr == root) return 0;

	return max(tree_depth_recursive(root->left), tree_depth_recursive(root->right)) + 1;
}

// level order traversal seems easiest for this job
size_t tree_depth_iterative(const Node *root) {
	if (nullptr == root) return 0;

	size_t height{};
	queue<const Node*> q{};
	q.push(root);

	while (!q.empty()) {
		height++;

		size_t qsize = q.size() + 1;  // at a time, qsize will tell the nodecount in same level
		while (1 < qsize) {
			const Node *curr_node = q.front();
			q.pop();
			if (nullptr != curr_node->left) {
				q.push(curr_node->left);
			}
			if (nullptr != curr_node->right) {
				q.push(curr_node->right);
			}
			qsize--;
		}
	}

	return height;
}

/** Balanced Binary tree
 * rule: for a particular node: (height(left subtree) - height(right subtree)) <= 1
 */
// NOTE: the problem with this approach is that it'll tell if tree is balanced
// only for the given particular node ie., it's possible the for root the tree
// is balanced, but some subtree of the tree is not balanced on the inside, the
// tree I've created for the demo is good example of it
/* bool balanced_binary_tree(const Node *root) {
	return abs(tree_depth_iterative(root->left) - tree_depth_iterative(root->right)) <= 1;
} */

// return -1, if tree is not balanced, else return the tree's height (ie., tree is balanced)
ssize_t balanced_binary_tree_another_shot(const Node *root) {
	if (nullptr == root) {
		return 0;
	}

	size_t lh = balanced_binary_tree_another_shot(root->left);
	size_t rh = balanced_binary_tree_another_shot(root->right);

	if ((max(lh, rh) - min(lh, rh)) > 1) {
		return -1;
	}
	return max(lh, rh) + 1;
}

// diameter of binary tree
// * longest path between two nodes, which doesn't necessarily needs to be passed from root node
void tree_diameter_brute_force(const Node *root, size_t& maxd) {
	if (nullptr == root) return;

	size_t lh = tree_depth_recursive(root->left);
	size_t rh = tree_depth_recursive(root->right);

	maxd = max(maxd, lh + rh);

	tree_diameter_brute_force(root->left, maxd);
	tree_diameter_brute_force(root->right, maxd);
}

// better approach is to not call functions to calculate the height of tree seperately
size_t tree_diameter(const Node *root, size_t &maxd) {
	if (nullptr == root) return 0;

	size_t lh = tree_diameter(root->left, maxd);
	size_t rh = tree_diameter(root->right, maxd);

	maxd = max(maxd, lh + rh);

	return max(lh, rh) + 1;
}

// maximum sum you can get from a path of tree (nodes can't be repeated)
int maximum_path_sum(const Node *root) {
	if (nullptr == root) return 0;

	return max(maximum_path_sum(root->left), maximum_path_sum(root->right)) + root->value;
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
	cout << "\n----------------\n";
	postorder_traversal_iterative_2stack(root);
	cout << "\n----------------\n";
	postorder_traversal_iterative_single_stack(root);
	cout << "\n----------------\n";
	trio_traversal_iterative(root);
	cout << "\n----------------\n";
	cout << "tree depth (recursive): " << tree_depth_recursive(root);
	cout << "\n----------------\n";
	cout << "tree depth (iterative): " << tree_depth_iterative(root);
	/* cout << "\n----------------\n";
	cout << "is tree balanced: " << balanced_binary_tree(root); */
	cout << "\n----------------\n";
	cout << "is tree balanced: " << balanced_binary_tree_another_shot(root);
	size_t maxd{};
	tree_diameter(root, maxd);
	cout << "\n----------------\n";
	cout << "diameter of tree: " << maxd;
	cout << "\n----------------\n";
	cout << "maximum path sum: " << maximum_path_sum(root);

	return 0;
}
