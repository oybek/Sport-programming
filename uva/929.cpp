
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

#define a_sz_MAX 1000

int rown,
	coln,
	a[a_sz_MAX][a_sz_MAX],
	dist[a_sz_MAX][a_sz_MAX];

struct cell {
	int x, y, w;

	cell(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	inline
	bool operator < (const cell & a) const {
		return !(w < a.w);
	}
};

/* source point is always [0][0] */
void dijkstra() {
	int i, j;
	priority_queue<cell> Q;

	for (i = 0; i < a_sz_MAX; ++i)
		for (j = 0; j < a_sz_MAX; ++j)
			dist[i][j] = INF;
	dist[0][0] = a[0][0];

	Q.push(cell(0, 0, dist[0][0]));
	while (!Q.empty()) {
		cell cur = Q.top();
		Q.pop();
		if (cur.w > dist[cur.x][cur.y])
			continue;

		if (cur.x-1 >= 0 &&
			dist[cur.x][cur.y] + a[cur.x-1][cur.y] < dist[cur.x-1][cur.y]) {
			dist[cur.x-1][cur.y] = dist[cur.x][cur.y] + a[cur.x-1][cur.y];
			Q.push(cell(cur.x-1, cur.y, dist[cur.x-1][cur.y]));
		}
		if (cur.x+1 < rown &&
			dist[cur.x][cur.y] + a[cur.x+1][cur.y] < dist[cur.x+1][cur.y]) {
			dist[cur.x+1][cur.y] = dist[cur.x][cur.y] + a[cur.x+1][cur.y];
			Q.push(cell(cur.x+1, cur.y, dist[cur.x+1][cur.y]));
		}
		if (cur.y-1 >= 0 &&
			dist[cur.x][cur.y] + a[cur.x][cur.y-1] < dist[cur.x][cur.y-1]) {
			dist[cur.x][cur.y-1] = dist[cur.x][cur.y] + a[cur.x][cur.y-1];
			Q.push(cell(cur.x, cur.y-1, dist[cur.x][cur.y-1]));
		}
		if (cur.y+1 < coln &&
			dist[cur.x][cur.y] + a[cur.x][cur.y+1] < dist[cur.x][cur.y+1]) {
			dist[cur.x][cur.y+1] = dist[cur.x][cur.y] + a[cur.x][cur.y+1];
			Q.push(cell(cur.x, cur.y+1, dist[cur.x][cur.y+1]));
		}
	}
}

int main() {
	int test_n, i, j;
	cin >> test_n;
	while (test_n--) {
		/* prepare stage */

		/* input stage */
		cin >> rown >> coln;
		for (i = 0; i < rown; ++i)
			for (j = 0; j < coln; ++j)
				cin >> a[i][j];

		/* solution & output */
		dijkstra();
		cout << dist[rown-1][coln-1] << endl;
	}

	return 0;
}

