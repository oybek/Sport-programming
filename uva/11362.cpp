
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define SIZE 10

struct prefix_tree {
	struct node {
		bool flag;
		node * next[SIZE];

		node() : flag(false) {
			for (int i = 0; i < SIZE; ++i)
				next[i] = NULL;
		}
	} * root;

	prefix_tree()
		: root(NULL)
	{}

	void push(const string & s) {
		push(s, s.begin(), root);
	}

	void push(const string & s, string::const_iterator it, node *& cur) {
		if (cur == NULL)
			cur = new node;

		if (it+1 == s.end()) {
			cur->flag = true;
			return;
		}

		push(s, it+1, cur->next[*it-'0']);
	}

	bool is_leaf(node * cur) {
		for (int i = 0; i < SIZE; ++i)
			if (cur->next[i])
				return false;
		return true;
	}

	bool is_consistent() {
		return is_consistent(root);
	}

	bool is_consistent(node * cur) {
		if (cur->flag) {
			return is_leaf(cur);
		}

		for (int i = 0; i < SIZE; ++i) {
			if (cur->next[i]) {
				if (!is_consistent(cur->next[i])) {
					return false;
		} } }

		return true;
	}

	void init() {
		init(root);
		root = new node;
	}

	void init(node * cur) {
		if (cur == NULL)
			return;

		for (int i = 0; i < SIZE; ++i)
			if (cur->next[i])
				init(cur->next[i]);

		delete cur;
	}
};

int main() {
	int test_n, n;
	string s;
	prefix_tree tree;

	cin >> test_n;
	while (test_n--) {
		/* prepare phase */
		tree.init();

		/* input phase */
		cin >> n;
		while (n--) {
			cin >> s;
			tree.push(s);
		}

		/* ouput phase */
		cout << (tree.is_consistent() ? "YES\n" : "NO\n");
	}

	return 0;
}

