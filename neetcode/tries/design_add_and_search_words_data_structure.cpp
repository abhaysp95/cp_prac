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

class WordDictionary {
	private:
		Node *head;

		bool dfs(const string& word, size_t x, Node *root) {
			Node *curr = root;
			for (size_t i = x; i < word.size(); i++) {
				if (word[i] == '.') {
					// check each of the child branches with dfs traversal (for character after the current
					// one)
					for (size_t j = 0; j < 26; j++) {
						if (curr->children[j] && dfs(word, i + 1, curr->children[j])) {
							return true;
						}
					}
					return false;
				} else {
					size_t idx = word[i] - 'a';
					if (curr->children[idx] == NULL) {
						return false;
					}
					curr = curr->children[idx];
				}
			}

			return curr->is_terminal;
		}

	public:
		WordDictionary() {
			this->head = new Node();
		}

		void addWord(string word) {
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
			return dfs(word, 0, this->head);
		}
};
