
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

inline void DEBUG(bool cond, const char * msg) {
#ifdef DO_DEBUG
	if (cond) {
		std::cerr << msg << '\n';
		exit(0);
	}
#endif
}

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

template <class T>
string to_string(T n) {
	if (n == 0) {
		return "0";
	}

	string s;
	for (int m = abs(n); m != 0; m /= 10) {
		s.push_back(static_cast<char>(m%10+'0'));
	}
	if (n < 0) {
		s.push_back('-');
	}
	reverse(s.begin(), s.end());
	return s;
}


#define vertex_sz_MAX	101
#define edges_sz_MAX	201

struct edge {
	int x, y, w, id;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw), id(-1)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}

	bool operator == (const edge & a) const {
		return id == a.id;
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
vector<edge> mst_edges;

/* return -1 if can't mst doesn't exists, otherwise returns its cost */
int build_mst(bool build, const edge & ignore_edge) {
	init_set();
	sort(edges, edges+edges_sz);

	int count = vertex_sz-1, cost = 0;
	for (int i = 0; count && i < edges_sz; ++i) {
		if (find_set(edges[i].x) == find_set(edges[i].y) ||
			edges[i] == ignore_edge)
			continue;

		--count;
		cost += edges[i].w;
		union_set(edges[i].x, edges[i].y);
		if (build)
			mst_edges.push_back(edges[i]);
	}

	return !count ? cost : -1;
}

string solve() {
	if (build_mst(true, edge(-1, -1, -1)) == -1) {
		return "No way";
	}

	int mst2_cost = -1;
	for (vector<edge>::iterator it = mst_edges.begin(); it != mst_edges.end(); ++it) {
		int mst_cost = build_mst(false, *it);

		if (mst_cost != -1) {
			mst2_cost = mst2_cost == -1 ? mst_cost : min(mst_cost, mst2_cost);
		}
	}

	return mst2_cost == -1 ? "No second way" : to_string(mst2_cost);
}

int main() {
	mst_edges.reserve(vertex_sz_MAX);

	int test_n;
	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		mst_edges.resize(0);

		cin >> vertex_sz >> edges_sz;
		for (int i = 0; i < edges_sz; ++i) {
			cin >> edges[i].x >> edges[i].y >> edges[i].w;
			edges[i].id = i;
		}

		cout << "Case #" << test_i << " : " << solve() << endl;
	}

	return 0;
}

