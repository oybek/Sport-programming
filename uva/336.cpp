
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

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define N_MAX 31

int N;
list<int> G[N_MAX];
bitset<N_MAX> visited;

int bfs(int n, int ttl) {
	visited.reset();
	queue<pair<int, int> > Q;

	Q.push(make_pair(n, ttl));
	visited[n] = true;

	int visited_n = 0;
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		++visited_n;

		for (list<int>::iterator it = G[cur.first].begin(); it != G[cur.first].end(); ++it) {
			if (!visited[*it] && cur.second > 0) {
				Q.push(make_pair(*it, cur.second-1));
				visited[*it] = true;
			}
		}
	}

	return visited_n;
}

int main() {
	int M, id, test_i;
	unordered_map<int, int> ids;

	for (test_i = 1; ; ) {
		/* prepare stage */
		id = 0;
		ids.clear();
		for (int i = 0; i < N_MAX; ++i)
			G[i].clear();


		/* input stage */
		cin >> M;
		if (!M)
			break;

		while (M--) {
			int n1, n2;
			cin >> n1 >> n2;
			if (ids.find(n1) == ids.end()) ids[n1] = id++;
			if (ids.find(n2) == ids.end()) ids[n2] = id++;

			G[ids[n1]].push_back(ids[n2]);
			G[ids[n2]].push_back(ids[n1]);
		}

		while (1) {
			int n, ttl;
			cin >> n >> ttl;
			if (!n && !ttl)
				break;

			cout	<< "Case " << test_i++ << ": "
					<< ids.size()-bfs(ids[n], ttl) << " nodes not reachable from node "
					<< n << " with TTL = " << ttl << ".\n";
		}
	}

	return 0;
}

