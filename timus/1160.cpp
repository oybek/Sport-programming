
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

#define N_MAX 1001
#define M_MAX 15001

/* ufds set */
int parent[N_MAX];
void init_set() {
	for (int i = 0; i < N_MAX; ++i) {
		parent[i] = i;
	}
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}
};

int N, M;
edge edges[M_MAX];
vector<edge> mst;

void build_mst() {
	sort(edges, edges+M);

	int count = N-1; /* mst has N-1 edges */
	for (int i = 0; count; ++i) {
		if (find_set(edges[i].x) == find_set(edges[i].y))
			continue;

		mst.push_back(edges[i]);
		union_set(edges[i].x, edges[i].y);
		--count;
	}

}

int main() {
	mst.reserve(N_MAX);
	init_set();

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
		cin >> edges[i].x >> edges[i].y >> edges[i].w;

	build_mst();

	cout	<< mst.back().w << endl
			<< mst.size() << endl;

	for (vector<edge>::const_iterator it = mst.begin(); it != mst.end(); ++it) {
		cout << it->x << ' ' << it->y << endl;
	}

	return 0;
}

