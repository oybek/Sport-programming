
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define N_MAX 31

int N;
char Q[N_MAX][N_MAX];

bool is_in_border(int x, int y) {
	return (x >= 0) && (y >= 0) && (x < N) && (y < N);
}

bool is_good_pos(int x, int y) {
	return !is_in_border(x, y) ? true : Q[x][y] != 'X';
}

bool is_good_queen(int x, int y) {
	for (int i = 1; i < N; ++i)
		if (is_good_pos(x-i, y-i) &&
			is_good_pos(x-i, y  ) &&
			is_good_pos(x-i, y+i) &&
			is_good_pos(x  , y-i) &&
			is_good_pos(x  , y+i) &&
			is_good_pos(x+i, y-i) &&
			is_good_pos(x+i, y  ) &&
			is_good_pos(x+i, y+i));
		else
			return false;
	return true;
}

bool is_YES() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (!is_good_queen(i, j))
				return false;
	return true;
}

void move_queen(pair<int, int> a, pair<int, int> b) {
	swap(Q[a.first][a.second], Q[b.first][b.second]);
}

void search_solution() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			if (Q[i][j] == 'X') {
				for (int d = 1; d < N; ++d) {
					if (is_in_border(i+d, j+d)) {
					}
				}
			}
		}
}

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; ++i)
			scanf("%s", Q[i]);

		if (is_YES()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}

		cout << endl;
	}

	return 0;
}

