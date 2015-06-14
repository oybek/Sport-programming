
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

#define vertex_num_MAX 11

vector<list<pair<int, int> > > G;
int dist[vertex_num_MAX],
	prev[vertex_num_MAX];

void dijkstra(int s) {
	priority_queue<pair<int, int> > Q;

	for (int i = 0; i < int(G.size()); ++i) {
		dist[i] = INF;
		prev[i] = -1;
	}
	dist[s] = 0;

	Q.push(make_pair(0, s));
	while (!Q.empty()) {
		int cur = Q.top().second, cur_d = -Q.top().first;
		Q.pop();
		if (cur_d > dist[cur])
			continue;

		for (list<pair<int, int> >::iterator it = G[cur].begin(); it != G[cur].end(); ++it) {
			if (dist[cur] + it->first < dist[it->second]) {
				dist[it->second] = dist[cur] + it->first;
				prev[it->second] = cur;
				Q.push(make_pair(-dist[it->second], it->second));
			}
		}
	}
}

int main() {
	int vertex_num;
	vector<int> path;

	for (int test_i = 1; ; ++test_i) {
		/* prepare stage */
		G.resize(0);
		path.resize(0);

		/* input stage */
		cin >> vertex_num;
		if (vertex_num == 0) break;

		G.resize(vertex_num);
		for (int i = 0; i < vertex_num; ++i) {
			int n;
			cin >> n;
			while (n--) {
				int b, w;
				cin >> b >> w;
				G[i].push_back(make_pair(w, --b));
			}
		}

		int a, b;
		cin >> a >> b; --a, --b;
		dijkstra(a);
		for (int i = b; i != -1; i = prev[i]) {
			path.push_back(i+1);
		}
		reverse(path.begin(), path.end());

		cout << "Case " << test_i << ": Path =";
		for (vector<int>::iterator it = path.begin(); it != path.end(); ++it) {
			cout << ' ' << *it;
		}
		cout << "; " << dist[b] << " second delay\n";
	}

	return 0;
}

