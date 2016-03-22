
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF LLONG_MAX

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define n_max 100001

int n, m;
struct edge {
	int v;
	ll w;

	edge(int av = 0, ll aw = 0)
		: v(av), w(aw)
	{}

	bool operator < (const edge & a) const {
		return !(w < a.w);
	}
};

vector<edge> G[n_max];
int path[n_max], path_size = 0;
ll dist[n_max];
priority_queue<edge> Q;

ll dijkstra(int src, int dst) {
	fill(dist, dist+n, INF);
	dist[src] = 0;

	Q.push(edge(src, dist[src]));

	while (!Q.empty()) {
		edge cur = Q.top(); Q.pop();

		if (cur.w > dist[cur.v])
			continue;

		for (auto it : G[cur.v]) {
			if (dist[cur.v] + it.w < dist[it.v]) {
				dist[it.v] = dist[cur.v] + it.w;
				Q.push(edge(it.v, dist[it.v]));
			}
		}
	}

	return dist[dst];
}

void get_path(int src, int dst) {
	path[path_size++] = dst;
	for (int cur = dst; cur != src; ) {
		for (auto edge : G[cur]) {
			if (dist[cur] == dist[edge.v] + edge.w) {
				cur = edge.v;
				break;
			}
		}
		path[path_size++] = cur;
	}
}

int main() {
	cin >> n >> m;

	{
		map<pair<int, int>, int> edges;
		for (int i = 0; i < m; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			if (a == b) {
				continue;
			}
			if (edges.find(make_pair(a-1, b-1)) == edges.end()) {
				edges[make_pair(a-1, b-1)] = w;
			} else {
				edges[make_pair(a-1, b-1)] = min(w, edges[make_pair(a-1, b-1)]);
			}
		}

		for (auto t : edges) {
			G[t.first.first ].push_back(edge(t.first.second, t.second));
			G[t.first.second].push_back(edge(t.first.first , t.second));
		}
	}

	if (dijkstra(0, n-1) == INF) {
		cout << -1;
	} else {
		get_path(0, n-1);
		for (int i = path_size-1; i >= 0; --i)
			cout << path[i]+1 << ' ';
	}

	return 0;
}

