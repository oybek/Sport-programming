
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

#define sz_MAX 1000000
#define x_MAX 2001

struct coord {
	int x, y;
	coord(int ax = 0, int ay = 0) : x(ax), y(ay) {}
} a[sz_MAX], b[sz_MAX];

int board[x_MAX][x_MAX];

#define MALL2 1000000001

int bfs(queue<coord> & Q) {
	while (! Q.empty()) {
		coord cur = Q.front(); Q.pop();
		/*if (board[cur.x][cur.y] == MALL2)*/
			/*continue;*/

#define PUSH(x0, y0, x, y) \
		if (x >= 0 && y >= 0 && x < x_MAX && y < x_MAX) { \
			switch (board[x][y]) { \
				case MALL2: \
					return board[x0][y0]+1; \
				case -1: \
					board[x][y] = board[x0][y0]+1; \
					Q.push(coord(x, y)); \
					break; \
			} \
		}

		PUSH(cur.x, cur.y, cur.x-1,   cur.y);
		PUSH(cur.x, cur.y, cur.x+1,   cur.y);
		PUSH(cur.x, cur.y,   cur.x, cur.y-1);
		PUSH(cur.x, cur.y,   cur.x, cur.y+1);
	}
	return 0;
}

void show(int x, int y) {
	for (int i = 0; i <= x; ++i) {
		for (int j = 0; j <= y; ++j)
			switch (board[i][j]) {
				case -1:
					cout << " .";
					break;
				case 0:
					cout << " #";
					break;
				case MALL2:
					cout << " #";
					break;
				default:
					cout << setw(2) << board[i][j];
					break;
			}
		cout << endl;
	}
}

int main() {
	int t, x, y;
	queue<coord> Q;

	while (1) {
		/* init stage */
		for (int i = 0; i < x_MAX; ++i)
			fill(board[i], board[i]+x_MAX, -1);
		while (!Q.empty())
			Q.pop();

		/* input stage */
		cin >> t;
		if (t == 0)
			break;
		while (t--) {
			cin >> x >> y;
			board[x][y] = 0;
			Q.push(coord(x, y));
		}
		cin >> t;
		while (t--) {
			cin >> x >> y;
			board[x][y] = MALL2;
		}

		cout << bfs(Q) << endl;
#ifdef DEBUG
		show(12, 12);
#endif
	}

	return 0;
}

