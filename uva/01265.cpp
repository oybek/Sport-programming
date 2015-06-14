
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

using namespace std;

#define vertex_sz_MAX	5001
#define edge_w_MAX		100001

typedef long long int64;

/* ufds */
namespace {
	int parent[vertex_sz_MAX];
	int size[vertex_sz_MAX];

	void init_set() {
		for (int i = 0; i < vertex_sz_MAX; ++i) {
			parent[i] = i;
			size[i] = 1;
		}
	}
	int find_set(int x) {
		return x == parent[x] ? x : parent[x] = find_set(parent[x]);
	}
	/* keeps track about newly formed components */
	void join_set(int x, int y, set<int> & new_comp) {
		x = find_set(x);
		y = find_set(y);

		if (x == y)
			return;

		if (size[x] > size[y]) {
			parent[y] = x;
			size[x] += size[y]; new_comp.insert(x);
			size[y] = 0; new_comp.erase(y);
		} else {
			parent[x] = y;
			size[y] += size[x]; new_comp.insert(y);
			size[x] = 0; new_comp.erase(x);
		}
	}
}

int vertex_sz, edges_sz, w_max;
list<pair<int, int> > edges[ edge_w_MAX ];

int64 solve() {
	init_set();

	set<int> new_comp;
	int64 count = 0;
	for (int w = w_max; w >= 1; --w) {
		new_comp.clear();

		/* add edges with same weights */
		for (list<pair<int, int> >::iterator it = edges[w].begin(); it != edges[w].end(); ++it) {
			join_set(it->first, it->second, new_comp);
		}

		for (set<int>::iterator it = new_comp.begin(); it != new_comp.end(); ++it) {
			count += size[*it];
		}
	}

	return count;
}

int main() {
	int test_n, x, y, w;
	cin >> test_n;

	while (test_n--) {
		/* prepare stage */
		w_max = 0;
		for (int i = 0; i < edge_w_MAX; ++i)
			edges[i].clear();

		/* input stage */
		cin >> vertex_sz >> edges_sz;
		while (edges_sz--) {
			cin >> x >> y >> w;
			w_max = max(w, w_max);
			edges[w].push_back(make_pair(x, y));
		}

		/* solve and output */
		cout << solve() << endl;
	}

	return 0;
}

