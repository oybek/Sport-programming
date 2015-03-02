
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

int R, C;
bitset<C_MAX> visited[R_MAX], land[R_MAX];

int solve(pair<int, int> start, pair<int, int> end) {
	queue<pair<pair<int, int>, int> > Q;

	Q.push(make_pair(start, 0));

	while (!Q.empty()) {
		pair<pair<int, int>, int> cur = Q.front(); Q.pop();

		if (cur.first == end) {
			return cur.second;
		}

#define PUSH(x, y, l)\
		if (x >= 0 && x < R && y >= 0 && y < C && \
			!land[x][y] && !visited[x][y]) { \
			visited[x][y] = true; \
			Q.push(make_pair(make_pair(x, y), l)); \
		}

		PUSH(cur.first.first-1, cur.first.second, cur.second+1);
		PUSH(cur.first.first+1, cur.first.second, cur.second+1);
		PUSH(cur.first.first, cur.first.second-1, cur.second+1);
		PUSH(cur.first.first, cur.first.second+1, cur.second+1);
	}

	assert(false);
	return 0;
}

int main() {
	while (1) {
		/* prepare stage */
		int r, rn, c, cn;
		for (int i = 0; i < R_MAX; ++i) {
			land[i].reset();
			visited[i].reset();
		}

		/* input stage */
		cin >> R >> C;
		if (!R && !C)
			break;

		cin >> rn;
		while (rn--) {
			cin >> r >> cn;
			while (cn--) {
				cin >> c;
				land[r][c] = 1;
			}
		}

		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		/* solve & output stage */
		cout << solve(make_pair(x1, y1), make_pair(x2, y2)) << endl;
	}

	return 0;
}

