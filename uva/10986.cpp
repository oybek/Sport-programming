
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

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define vertices_n_MAX	20000
#define edges_n_MAX		50000

struct edge {
	int v, w;

	edge(int av, int aw)
		: v(av), w(aw)
	{}

	bool operator < (const edge & a) const {
		return !(w < a.w);
	}
};

vector<list<edge> > G;
int vertices_n,
	edges_n,
	dist[vertices_n_MAX];

void dijkstra(int src) {
	priority_queue<edge> Q;

	for (int i = 0; i < vertices_n; ++i)
		dist[i] = INF;
	dist[src] = 0;

	Q.push(edge(src, dist[src]));
	while (!Q.empty()) {
		edge cur = Q.top(); Q.pop();
		if (cur.w > dist[cur.v])
			continue;

		for (list<edge>::iterator it = G[cur.v].begin(); it != G[cur.v].end(); ++it) {
			if (dist[cur.v] + it->w < dist[it->v]) {
				dist[it->v] = dist[cur.v] + it->w;
				Q.push(edge(it->v, dist[it->v]));
			}
		}
	}
}

int main() {
	int test_n, a, b, w, src, dst;

	G.reserve(vertices_n_MAX);

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		/* prepare stage */
		G.resize(0);

		/* input stage */
		cin >> vertices_n >> edges_n >> src >> dst;
		G.resize(vertices_n);
		while (edges_n--) {
			cin >> a >> b >> w;
			G[a].push_back(edge(b, w));
			G[b].push_back(edge(a, w));
		}

		/* solution stage */
		dijkstra(src);
		cout << "Case #" << test_i << ": ";
		if (dist[dst] == INF) {
			cout << "unreachable\n";
		} else {
			cout << dist[dst] << "\n";
		}
	}

	return 0;
}

