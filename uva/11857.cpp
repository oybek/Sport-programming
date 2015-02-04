
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

#define vertex_sz_MAX	 1000001
#define edges_sz_MAX	 1000001

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}
};

int parent[vertex_sz_MAX];
void init_set() {
	for (int i = 0; i < vertex_sz_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

int vertex_sz, edges_sz;
edge edges[edges_sz_MAX];

/* returns the cost of mst */
int build_mst() {
	sort(edges, edges+edges_sz);
	init_set();

	int max_w = -INF, count = vertex_sz-1;
	for (int i = 0; count && i < edges_sz; ++i) {
		if (find_set(edges[i].x) == find_set(edges[i].y))
			continue;

		union_set(edges[i].x, edges[i].y);
		max_w = max(edges[i].w, max_w);
		--count;
	}

	return (count ? -1 : max_w);
}

int main() {
	for (;;) {
		/* input */
		cin >> vertex_sz >> edges_sz;
		if (!vertex_sz && !edges_sz)
			break;

		for (int i = 0; i < edges_sz; ++i) {
			cin >> edges[i].x >> edges[i].y >> edges[i].w;
		}

		/* solve and output */
		int ans = build_mst();
		if (ans == -1) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << ans << '\n';
		}
	}

	return 0;
}

