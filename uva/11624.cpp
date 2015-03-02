
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

#define R_MAX 1001
#define C_MAX 1001

int R, C, time[R_MAX][C_MAX];
string maze[R_MAX];
bitset<C_MAX> visited[R_MAX];

void bfs_fire(int x, int y) {
	queue<pair<pair<int, int>, int> > Q;
	for (int i = 0; i < R_MAX; ++i)
		visited[i].reset();

	Q.push(make_pair(x, y,), 0);

	while (!Q.emtpy()) {
		pair<pair<int, int>, int> cur = Q.front(); Q.pop();
		time[cur.first.first][cur.first.second] = cur.second;

#define PUSH(x, y, l) \
		if (x >= 0 && x < R && y >= 0 && y < C && \
			maze[x][y] != '#' && !visisted[x][y]) { \
			visited[x][y] = true; \
			Q.push(make_pair(make_pair(x, y), l)); \
		}

		PUSH(cur.first.first-1, cur.first.second, cur.second+1);
		PUSH(cur.first.first+1, cur.first.second, cur.second+1);
		PUSH(cur.first.first, cur.first.second-1, cur.second+1);
		PUSH(cur.first.first, cur.first.second+1, cur.second+1);
	}
}

int bfs_joe(int x, int y) {
}

int main() {
	int test_n;

	cin >> test_n;
	while (test_n--) {
		/* prepare stage */
		for (int i = 0; i < R_MAX; ++i)
			for (int j = 0; j < C_MAX; ++j)
				time[i][j] = 0;

		/* input stage */
		cin >> R >> C;
		for (int i = 0; i < R; ++i)
			cin >> maze[i];

		/* solution stage */
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (maze[i][j] == 'F') {
					bfs_fire(i, j);
					i = R;
					break;
				}

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (maze[i][j] == 'J') {
					int ans = bfs_joe(i, j);
					i = R;
					break;
				}
	}

	return 0;
}

