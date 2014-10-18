
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define WIN1	1
#define WIN2	-1
#define DRAW	0

#define isleaf(n) (n->child.size() == 0)

struct tree_node_t {
	int						val;
	vector<tree_node_t *>	child;
};

int getwin(const tree_node_t * node, const bool turn)
{
	if (node == NULL)
		return 2;

	if (isleaf(node))
		return node->val;

	int r, i;
	switch (turn) {
		case 0: // player one
			r = getwin(node->child[0], !turn);
			for (i = 1; i < node->child.size(); ++i)
				switch (getwin(node->child[i], !turn)) {
					case WIN1:
						r = WIN1;
						break;

					case DRAW:
						if (r != WIN1)
							r = DRAW;
						break;

					case WIN2:
						if ((r != WIN1) && (r != DRAW))
							r = WIN2;
						break;
				}
			break;

		case 1: // player two
			r = getwin(node->child[0], !turn);
			for (i = 1; i < node->child.size(); ++i)
				switch (getwin(node->child[i], !turn)) {
					case WIN2:
						r = WIN2;
						break;

					case DRAW:
						if (r != WIN2)
							r = DRAW;
						break;

					case WIN1:
						if ((r != WIN2) && (r != DRAW))
							r = WIN1;
						break;
				}
			break;
	}
	return r;
}

#if 0
void show(tree_node_t * cur, int tab)
{
	for (int i = 0; i < tab; ++i)
		cerr << ' ';
	cerr << cur->val << endl;

	if (cur->left)
		show(cur->left, tab+1);
	if (cur->right)
		show(cur->right, tab+1);
}
#endif

int main()
{
	int n, i;
	tree_node_t * node;

	cin >> n;
	node = new tree_node_t [n+1];
	node[1].val = 1;

	// building tree
	for (int i = 2; i <= n; ++i) {
		char c;
		int p, v;

		cin >> c;

		switch (c) {
			case 'N':
				cin >> p;
				node[p].child.push_back(node+i);
				node[i].val = i;
				break;

			case 'L':
				cin >> p >> v;
				node[p].child.push_back(node+i);
				node[i].val = v;
				break;
		}
	}

	switch (getwin(node+1, 0)) {
		case WIN1:
			cout << "+1" << endl;
			break;

		case WIN2:
			cout << "-1" << endl;
			break;

		case DRAW:
			cout << "0" << endl;
			break;
	}

	return 0;
}

