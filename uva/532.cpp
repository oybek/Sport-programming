
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

#define L_MAX 30
#define R_MAX 30
#define C_MAX 30

int L, R, C;
bitset<C_MAX> visited[L_MAX][R_MAX];
string dungeon[L_MAX][R_MAX];

struct triple {
	int x, y, z;
	triple(int ax = 0, int ay = 0, int az = 0)
		: x(ax), y(ay), z(az)
	{}
};

int bfs(int x, int y, int z) {
	queue<pair<triple, int> > Q;

	Q.push(make_pair(triple(x, y, z), 0));

	while (!Q.empty()) {
		pair<triple, int> cur = Q.front(); Q.pop();

		if (dungeon[cur.first.x][cur.first.y][cur.first.z] == 'E')
			return cur.second;

#define PUSH(x, y, z, l) \
		if (x >= 0 && x < L && y >= 0 && y < R && z >= 0 && z < C &&\
			dungeon[x][y][z] != '#' && !visited[x][y][z]) {\
			visited[x][y][z] = true;\
			Q.push(make_pair(triple(x, y, z), l));\
		}

		PUSH(cur.first.x-1, cur.first.y, cur.first.z, cur.second+1);
		PUSH(cur.first.x+1, cur.first.y, cur.first.z, cur.second+1);
		PUSH(cur.first.x, cur.first.y-1, cur.first.z, cur.second+1);
		PUSH(cur.first.x, cur.first.y+1, cur.first.z, cur.second+1);
		PUSH(cur.first.x, cur.first.y, cur.first.z-1, cur.second+1);
		PUSH(cur.first.x, cur.first.y, cur.first.z+1, cur.second+1);
	}

	return -1;
}

int solve() {
	for (int x = 0; x < L; ++x)
		for (int y = 0; y < R; ++y)
			for (int z = 0; z < C; ++z)
				if (dungeon[x][y][z] == 'S')
					return bfs(x, y, z);
	return -1;
}

int main() {
	while (1) {
		/* prepare stage */
		for (int x = 0; x < L; ++x)
			for (int y = 0; y < R; ++y)
				visited[x][y].reset();

		/* input stage */
		cin >> L >> R >> C;
		if (!L && !R && !C)
			break;
		for (int i = 0; i < L; ++i)
			for (int j = 0; j < R; ++j)
				cin >> dungeon[i][j];

		int ans = solve();
		if (ans == -1) {
			cout << "Trapped!\n";
		} else {
			cout << "Escaped in " << ans << " minute(s).\n";
		}
	}

	return 0;
}

