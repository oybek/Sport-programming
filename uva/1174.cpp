
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
#include <unordered_map>

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

#define vertex_sz_MAX 2001
#define edges_sz_MAX 50001

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}
};

/* ufds */
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

map<string, int> str_id;

/* returns weight of mst */
int solve() {
	init_set();
	sort(edges, edges+edges_sz);

	int mst_cost = 0, count = vertex_sz-1;
	for (int i = 0; count; ++i) {
		if (find_set(edges[i].x) == find_set(edges[i].y))
			continue;

		union_set(edges[i].x, edges[i].y);
		mst_cost += edges[i].w;
		--count;
	}

	return mst_cost;
}

int main() {
	bool f = true;
	int test_n, id, w;
	string s1, s2;

	cin >> test_n;
	while (test_n--) {
		/* prepare stage */
		id = 0;
		str_id.clear();

		/* input stage */
		cin >> vertex_sz >> edges_sz;
		for (int i = 0; i < edges_sz; ++i) {
			cin >> s1 >> s2 >> w;

			if (str_id.find(s1) == str_id.end()) str_id[s1] = id++;
			if (str_id.find(s2) == str_id.end()) str_id[s2] = id++;

			edges[i] = edge(str_id[s1], str_id[s2], w);
		}

		/* solution and output */
		if (f) f = false;
		else cout << endl;
		cout << solve() << endl;
	}

	return 0;
}

