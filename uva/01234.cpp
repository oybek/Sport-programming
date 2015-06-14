
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

#define edges_sz_MAX 100001
#define vertex_sz_MAX 10001

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}

	bool operator == (const edge & a) const {
		return (x == a.x) && (y == a.y);
	}
};

/* ufds */
int parent[edges_sz_MAX];
void init_set() {
	for (int i = 0; i < vertex_sz_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void join_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

int vertex_sz, edges_sz;
vector<edge> edges;
vector<edge> mst_edges;

void build_mst() {
	init_set();
	/* we are building maximal spanning tree */
	sort(edges.rbegin(), edges.rend());

	int count = vertex_sz-1;
	for (vector<edge>::iterator it = edges.begin(); count && it != edges.end(); ++it) {
		if (find_set(it->x) == find_set(it->y))
			continue;

		--count;
		join_set(it->x, it->y);
		mst_edges.push_back(*it);
	}
}

/* returns sum of edges not in mst */
int solve() {
	build_mst();
	int mst_cost = 0, cost = 0;

	for (vector<edge>::iterator it = edges.begin(); it != edges.end(); ++it) {
		cost += it->w;
	}
	for (vector<edge>::iterator it = mst_edges.begin(); it != mst_edges.end(); ++it) {
		mst_cost += it->w;
	}

	return cost - mst_cost;
}

int main() {
	int test_n, x, y, w;
	edges.reserve(edges_sz_MAX);
	mst_edges.reserve(vertex_sz_MAX);

	cin >> test_n;
	while (test_n--) {
		/* prepare stage */
		edges.resize(0);

		/* input stage */
		cin >> vertex_sz >> edges_sz;
		while (edges_sz--) {
			cin >> x >> y >> w;
			edges.push_back(edge(x, y, w));
		}

		/* solution and ouput */
		cout << solve() << endl;
	}

	return 0;
}

