
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

#define INF 1000000009
#define SQR(x) ((x)*(x))

using namespace std;

typedef pair<pair<int, int>, pair<int, int> > xyxy;
typedef unsigned long long uint64;
typedef long long int64;

#define n_max 1000
#define mk make_pair

queue<xyxy> Q;
int n, m, dist[n_max][n_max];

#define distance(a, b) (SQR(a.first - b.first) + SQR(a.second - b.second))

void bfs() {
	int x, y;
	while (!Q.empty()) {
		xyxy t = Q.front(); Q.pop();

		x = t.first.first;
		y = t.first.second;

		dist[x][y] = min(distance(t.first, t.second), dist[x][y]);

		if (x-1 >= 0 && distance(mk(x-1, y), t.second) < dist[x-1][y])
			Q.push(mk(mk(x-1, y), t.second));

		if (x+1 < n && distance(mk(x+1, y), t.second) < dist[x+1][y])
			Q.push(mk(mk(x+1, y), t.second));

		if (y-1 >= 0 && distance(mk(x, y-1), t.second) < dist[x][y-1])
			Q.push(mk(mk(x, y-1), t.second));

		if (y+1 < m && distance(mk(x, y+1), t.second) < dist[x][y+1])
			Q.push(mk(mk(x, y+1), t.second));
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string t;
		cin >> t;
		for (int j = 0; j < m; ++j) {
			switch (t[j]) {
				case '0':
					dist[i][j] = INF;
					break;
				case '1':
					Q.push(mk(mk(i, j), mk(i, j)));
					dist[i][j] = 0;
					break;
			}
		}
	}

	bfs();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << dist[i][j] << ' ';
		cout << endl;
	}

	return 0;
}

