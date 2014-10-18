
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define NO_COLOR 0
#define BLACK 1
#define WHITE 2

#define MAX_V 1000+1
int v_n;
int color[ MAX_V ];
vector<int> g[ MAX_V ];

vector<int> black_v;

int get_blackn() {
	int n = 0;
	for (int i = 1; i <= v_n; ++i)
		n += (color[i] == BLACK);
	return n;
}

bool can_be(int i, int col) {
	if (col == WHITE)
		return true;

	for (int j = 0; j < int(g[i].size()); ++j)
		if (color[ g[i][j] ] == BLACK)
			return false;

	return true;
}

void backtrack(int cur, int colored_n) {
	if (colored_n == v_n) {
		if (int(black_v.size()) < get_blackn()) {
			black_v.resize(0);
			for (int i = 0; i < v_n; ++i)
				if (color[i] == BLACK)
					black_v.push_back(i);
		}
	}

	if (color[cur] != NO_COLOR)
		return;

	for (int i = 0; i < int(g[cur].size()); ++i) {
		if (can_be(cur, WHITE)) {
			color[cur] = WHITE;
			backtrack(g[cur][i], colored_n+1);
		}

		if (can_be(cur, BLACK)) {
			color[cur] = BLACK;
			backtrack(g[cur][i], colored_n+1);
		}

		color[cur] = NO_COLOR;
	}
}

int main() {
	int tt, e_n, x, y;

	for (int i = 0; i < MAX_V; ++i)
		g[i].reserve(MAX_V);

	cin >> tt;
	while (tt--) {
		cin >> v_n >> e_n;

		for (int i = 0; i < v_n; ++i) {
			color[i] = NO_COLOR;
			g[i].resize(0);
		}

		while (e_n--) {
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		backtrack(0, 0);
	}

	return 0;
}

