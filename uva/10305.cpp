
#include <list>
#include <queue>
#include <iostream>
using namespace std;

#define MAX_NODE 100

struct node_t {
	vector<int> child;
	vector<int> parent;
};

int n;
node_t G[ MAX_NODE+1 ];
bool sign[ MAX_NODE+1 ];

void bfs(int root, list<int> & order) {
	sign[ root ] = true;
	queue<int> Q;
	Q.push(root);

	while ( !Q.empty() ) {
		int cur = Q.front(); Q.pop();
		order.push_back(cur);

		for ( int i = 0; i < (int) G[ cur ].child.size(); ++i )
			if ( !sign[ G[ cur ].child[i] ] ) {
				sign[ G[ cur ].child[i] ] = true;
				Q.push(G[ cur ].child[i]);
			}
	}
}

int main() {
	int m, i, x, y;
	list<int> order;
	list<int>::iterator it;

	for ( ;; ) {
		cin >> n >> m;

		if ( !n && !m )
			break;

		for ( i = 0; i < MAX_NODE; ++i ) {
			G[ i ].child.resize(0);
			G[ i ].parent.resize(0);
			sign[ i ] = false;
		}

		while ( m-- ) {
			cin >> x >> y;
			G[ x ].child.push_back(y);
			G[ y ].parent.push_back(x);
		}

		order.clear();
		for ( i = 1; i <= n; ++i )
			if ( (G[ i ].parent.size() == 0) && !sign[i] )
				bfs(i, order);

		cout << order.front();
		for ( it = order.begin(), ++it; it != order.end(); ++it )
			cout << ' ' << *it;
		cout << endl;
	}

	return 0;
}

