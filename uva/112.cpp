
#include <cmath>
#include <cctype>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int n;
	node * left,
		 * right;
	
	node() 
		: n(0)
		, left(NULL)
		, right(NULL)
	{}
};

class ttree {
	private:
		node * root;

	public:
		ttree() {
			root = new node;
		}

		inline void build() { root = dfs_build(root); }
		inline void show() { dfs_show(root, 0); }

		void dfs_show(node * cur, int deep)
		{
			for (int i = 0; i < deep; ++i)
				cout << "  ";
			cout << cur->n << endl;

			if (cur->left)
				dfs_show(cur->left, deep+1);
			if (cur->right)
				dfs_show(cur->right, deep+1);
		}

		node * dfs_build(node * cur)
		{
			char c;
			while ( (c = cin.get()) != ')' )
			{
				switch (c) {
					case '0': case '1': case '2': case '3': case '4':
					case '5': case '6': case '7': case '8': case '9':
						cin.putback(c);
						cur = new node;
						cin >> cur->n;
					break;

					case '(':
						if ( cur->left == NULL )
							cur->left = dfs_build(cur->left);
						else
							cur->right = dfs_build(cur->right);
					break;

					default:
					break;
				}
			}
			return cur;
		}
};

int main()
{
	int n;
	char c;
	ttree tree;

	while ( cin >> n )
	{
		while ( (c = cin.get()) != '(' );

		//tree.clear();

		tree.build();
		tree.show();
	}

	return 0;
}


