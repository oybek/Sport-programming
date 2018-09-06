
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define N_MAX 101

struct coord {
	int x;
	int y;

	coord(int x, int y) : x(x), y(y) {}

	bool operator== (const coord a) const {
		return x == a.x && y == a.y;
	}
};

int N, M, K, k;
string maze[N_MAX];

bool solve_maze(coord start, coord pos, coord end) {
	// we came here mark as X
	maze[pos.x][pos.y] = 'X';

	// we reached goal
	if (pos == end)
		return true;

	// position is called 'good' if it is on good path
	// path is called good if it connects the 'start' and the 'end'
	bool good_pos = false;

	// number of options we have from this pos
	int options_num = 0;

	if (pos.x-1 >= 0 && maze[pos.x-1][pos.y] == '.') {
		++options_num;
		good_pos |= solve_maze(start, coord(pos.x-1, pos.y), end);
	}
	if (pos.x+1  < N && maze[pos.x+1][pos.y] == '.') {
		++options_num;
		good_pos |= solve_maze(start, coord(pos.x+1, pos.y), end);
	}
	if (pos.y-1 >= 0 && maze[pos.x][pos.y-1] == '.') {
		++options_num;
		good_pos |= solve_maze(start, coord(pos.x, pos.y-1), end);
	}
	if (pos.y+1  < M && maze[pos.x][pos.y+1] == '.') {
		++options_num;
		good_pos |= solve_maze(start, coord(pos.x, pos.y+1), end);
	}

	if (good_pos && options_num > 1)
		++k;

	return good_pos;
}

coord find_start() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (maze[i][j] == 'M') {
				maze[i][j] = '.';
				return coord(i, j);
			}
		}
	}
	assert(false);
}

coord find_end() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (maze[i][j] == '*') {
				maze[i][j] = '.';
				return coord(i, j);
			}
		}
	}
	assert(false);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> N >> M;

		for (int i = 0; i < N; ++i)
			cin >> maze[i];

		cin >> K;

		k = 0;

		coord start = find_start();
		coord end = find_end();

		solve_maze(start, start, end);

		cout << (K == k ? "Impressed" : "Oops!") << endl;
	}

	return 0;
}

