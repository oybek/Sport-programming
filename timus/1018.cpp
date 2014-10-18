
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class tree_node_t {
	public:
		int weight;

		tree_node_t * left;
		tree_node_t * right;
		tree_node_t * parent;

		tree_node_t(int w) : weight(w)
							 ,left(NULL), right(NULL), parent(NULL) {}
};

class tree_t {
	private:
		tree_node_t * node[101];

	public:
		long sum;

		tree_t() : sum(0)
		{
			for (int i = 0; i < 101; ++i)
				node[i] = NULL;
		}

		void add(int a, int b, int w)
		{
			sum += w;
			if ((node[a] == NULL) && (node[b] == NULL)) {
				if (a > b) swap(a, b);

				node[a] = new tree_node_t(0);
				node[b] = new tree_node_t(w);

				node[a]->left = node[b];
				node[b]->parent = node[a];
			}
			else if (node[a] == NULL) {
				if (node[b]->left == NULL)
					node[b]->left = node[a] = new tree_node_t(w);
				else if (node[b]->right == NULL)
					node[b]->right = node[a] = new tree_node_t(w);

				node[a]->parent = node[b];
			}
			else if (node[b] == NULL) {
				if (node[a]->left == NULL)
					node[a]->left = node[b] = new tree_node_t(w);
				else if (node[a]->right == NULL)
					node[a]->right = node[b] = new tree_node_t(w);

				node[b]->parent = node[a];
			}
		}

		void get_leafs(tree_node_t * cur, vector<tree_node_t*> & leafs)
		{
			bool leaf = true;

			if (cur->left)
				get_leafs(cur->left, leafs), leaf = false;
			if (cur->right)
				get_leafs(cur->right, leafs), leaf = false;

			if (leaf)
				leafs.push_back(cur);
		}

		void killmin()
		{
			vector<tree_node_t *> leaf;
			get_leafs(node[1], leaf);

			int min = 0;
			for (int i = 1; i < leaf.size(); ++i)
				if (leaf[i]->weight < leaf[min]->weight)
					min = i;

			sum -= leaf[min]->weight;

			if (leaf[min] != node[1])
				if (leaf[min]->parent->right == leaf[min]) {
					leaf[min]->parent->right = NULL;
					delete leaf[min];
				}
				else if (leaf[min]->parent->left == leaf[min]) {
					leaf[min]->parent->left = NULL;
					delete leaf[min];
				}
		}
};

int main()
{
	tree_t tree;
	int N, Q, D, a, b, w;

	cin >> N >> Q;
	D = N-Q-1;

	while (--N) {
		cin >> a >> b >> w;
		tree.add(a, b, w);
	}

	while (D--) {
		tree.killmin();
	}

	cout << tree.sum << endl;

	return 0;
}

