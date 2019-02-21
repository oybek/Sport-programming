
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

struct node {
	ll val = 0;
	node* left = nullptr;
	node* right = nullptr;
};

node* build_tree(istream& cin) {
	char c;
	node* cur = nullptr;
	while ((c = cin.get()) != EOF) {
		switch (c) {
			default:
				break;

			case '(':
				if (cur->left == nullptr) {
					cur->left = build_tree(cin);
				} else {
					cur->right = build_tree(cin);
				}
				break;

			case ')':
				return cur;

			case '-':
			case '0': case '1':
			case '2': case '3':
			case '4': case '5':
			case '6': case '7':
			case '8': case '9':
				cin.unget();
				cur = new node;
				cin >> cur->val;
				break;
		}
	}
	return cur;
}

void draw_tree(node* cur, int depth = 0) {
	for (int i = 0; i < depth; ++i)
		cout << '.';

	if (cur == nullptr) {
		cout << "null" << endl;
	} else {
		cout << cur->val << endl;
		draw_tree(cur->left, depth+1);
		draw_tree(cur->right, depth+1);
	}
}

bool good_tree(node* cur, ll sum, ll needed_sum) {
	if (cur->left == nullptr && cur->right == nullptr) {
		cout << sum << endl;
		return sum == needed_sum;
	}

	return ( cur->left ? good_tree( cur->left, sum+cur->val, needed_sum) : false)
		|| (cur->right ? good_tree(cur->right, sum+cur->val, needed_sum) : false);

}

int main() {
#ifdef LOCAL
	TEST__calc_sum();
#endif

	int needed_sum;
	while (cin >> needed_sum) {
		while (cin.get() != '(');
		node* root = build_tree(cin);
		//draw_tree(root);
		cout << (good_tree(root, 0, needed_sum) ? "yes" : "no") << endl;
	}

	return 0;
}

