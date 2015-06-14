
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

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return	w == a.w ? (x == a.x ? y < a.y : x < a.x) : (w < a.w);
	}
};

#define vertex_sz_MAX 27
#define edges_sz_MAX 730

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

int vertex_sz;
vector<edge> edges, mst_edges;

void build_mst() {
	sort(edges.begin(), edges.end());
	init_set();

	int count = vertex_sz-1;
	for (vector<edge>::iterator it = edges.begin(); count; ++it) {
		if (find_set(it->x) == find_set(it->y))
			continue;

		union_set(it->x, it->y);
		mst_edges.push_back(*it);
		--count;
	}
}

int main() {
	char c;
	int test_n, w;
	mst_edges.reserve(vertex_sz_MAX);
	edges.reserve(edges_sz_MAX);

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		/* prepare stage */
		mst_edges.resize(0);
		edges.resize(0);

		/* input */
		cin >> vertex_sz;
		for (int i = 0; i < vertex_sz; ++i) {
			for (int j = 0; j < vertex_sz; ++j) {
				cin >> w;
				while ((c = cin.get()) != ',' && c != '\n');

				if (i < j && w != 0)
					edges.push_back(edge(i, j, w));
			}
		}

		/* solution and ouput */
		build_mst();
		cout << "Case " << test_i << ":\n";
		for (vector<edge>::iterator it = mst_edges.begin(); it != mst_edges.end(); ++it) {
			cout	<< static_cast<char>(it->x+'A') << '-'
					<< static_cast<char>(it->y+'A') << ' '
					<< it->w << endl;
		}
	}

	return 0;
}

