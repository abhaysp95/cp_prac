#include <bits/stdc++.h>

using namespace std;

struct Node {
	Node *children[26]; // constraint is that "word" and "prefix" will contain
						// only lowercase alphabet (else we could also use hashmap
						// or similar)
	bool is_terminal;
	Node() {
		for (size_t i = 0; i < 26; i++) {
			this->children[i] = NULL;
		}
		this->is_terminal = false;
	}
};

class Trie {
	private:
		Node *head;
	public:
		Trie() {
			this->head = new Node();
		}

		void insert(string word) {
			Node *tmp = this->head;
			for (const char c: word) {
				size_t idx = c - 'a';
				if (tmp->children[idx] == NULL) {
					tmp->children[idx] = new Node();
				}
				tmp = tmp->children[idx];
			}
			tmp->is_terminal = true;
		}

		bool search(string word) {
			Node *tmp = this->head;
			for (const char c: word) {
				size_t idx = c - 'a';
				if (tmp->children[idx] == NULL) {
					return false;
				}
				tmp = tmp->children[idx];
			}

			return tmp->is_terminal;
		}

		bool startsWith(string prefix) {
			Node *tmp = this->head;
			for (const char c: prefix) {
				size_t idx = c - 'a';
				if (tmp->children[idx] == NULL) {
					return false;
				}
				tmp = tmp->children[idx];
			}

			return true;
		}
};
