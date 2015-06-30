
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

#define N 8

char board[N][N];

#define GOOD(x, y) ((x >= 0) && (x < N) && (y >= 0) && (y < N))

bool can_attack(int x, int y, int dx, int dy) {
	if (!GOOD(x+dx, y+dy)) {
		return false;
	}
	if (board[x+dx][y+dy] == 0) {
		return false;
	}
	if (board[x][y] == board[x+dx][y+dy]) {
		return false;
	}
	if (GOOD(x+2*dx, y+2*dy) && board[x+2*dx][y+2*dy] == 0) {
		return true;
	}
	return false;
}

bool is_ok() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (board[i][j] != 0) {
				if (can_attack(i, j, -1, -1) ||
					can_attack(i, j, -1, +1) ||
					can_attack(i, j, +1, -1) ||
					can_attack(i, j, +1, +1)
					) {
					return false;
				}
			}
		}
	}
	return true;
}

#if 0
void show_board() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << int(board[i][j]);
		cout << endl;
	}
}
#endif

int main() {
	memset(board, 0, sizeof(char)*N*N);

	int t = 0, i;
	for (i = 0; i < 32; ++i) {
		string s;
		cin >> s;

		board[s[0]-'a'][s[1]-'1'] = t; t = (t == 1 ? 2 : 1);

		if (!is_ok()) {
			break;
		}
	}
	if (i == 32) {
		cout << "Draw\n";
	} else {
		cout << i+1 << endl;
	}

	return 0;
}

