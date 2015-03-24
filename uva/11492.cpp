
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define G_SIZE_MAX 10000

struct edge {
	int v, w;

	edge(int av = 0, int aw = 0)
		: v(av), w(aw)
	{}

	bool operator < (const edge & a) const {
		return !(w < a.w);
	}
};

int dist[G_SIZE_MAX],
	G_size;
list<edge> G[G_SIZE_MAX];
unordered_map<string, int> idof;

int dijkstra(int src, int dst) {
	priority_queue<edge> Q;

	for (int i = 0; i < G_size; ++i)
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

	return dist[dst];
}

int main() {
	int edge_n, id, src, dst;
	string s1, s2, s3;

	while (1) {
		/* prepare */
		id = 0;
		idof.clear();
		for (int i = 0; i < G_SIZE_MAX; ++i)
			G[i].clear();

		/* input */
		cin >> edge_n;
		if (edge_n == 0)
			break;

		cin >> s1 >> s2;

		idof.insert(make_pair(s1, src = id++));
		idof.insert(make_pair(s2, dst = id++));

		while (edge_n--) {
			cin >> s1 >> s2 >> s3;

			if (idof.find(s1) == idof.end()) idof.insert(make_pair(s1, id++));
			if (idof.find(s2) == idof.end()) idof.insert(make_pair(s2, id++));

			G[idof[s1]].push_back(edge(idof[s2], s3.size()));
			G[idof[s2]].push_back(edge(idof[s1], s3.size()));
		}

		G_size = idof.size();

		/* output */
		int t = dijkstra(src, dst);
		if (t == INF)
			cout << "impossivel\n";
		else
			cout << t << endl;
	}

	return 0;
}

