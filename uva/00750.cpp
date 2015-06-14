
#include <set>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

/*
 * 1. Gen all solutions
 */

#define MAX_CONFIG_SIZE 8

int config_n = 0;
int config[100][ MAX_CONFIG_SIZE+1 ];

bool can_be_placed(int config_sz, int row, int col) {
	for (int i = 1; i <= config_sz; ++i) {
		if (i == row
		|| config[config_n][i] == col
		|| abs(i - row) == abs(config[config_n][i] - col))
			return false;
	}
	return true;
}

void backtrack(int config_sz) {
	if (config_sz == 8) {
		// do something;
		for (int i = 1; i <= 8; ++i)
			config[config_n+1][i] = config[config_n][i];
		++config_n;
	} else {
		int last_row;

		if (config_sz == 0)
			last_row = 0;
		else
			last_row = config_sz;

		for (int col = 1; col <= 8; ++col) {
			if (can_be_placed(config_sz, last_row+1, col)) {

				config[config_n][ ++config_sz ] = col;

				backtrack(config_sz);

				--config_sz;
			}
		}
	}
}

/* returns true if n-th config has queen at x, y */
bool does_match(int n, int x, int y) {
	return config[n][x] == y;
}

int main() {
	/* generating all solutions */
	backtrack(0);


	int N;
	cin >> N;

	bool first = true;

	while (N--) {
		int x, y;
		cin >> x >> y;

		if (first) first = false;
		else cout << endl;

		cout	<< "SOLN       COLUMN"			<< endl
				<< " #      1 2 3 4 5 6 7 8"	<< endl << endl;

		for (int i = 0, c = 1; i < config_n; ++i) {
			if (config[i][y] == x) {
				printf("%2d     ", c);
				for (int i2 = 1; i2 <= 8; ++i2)
					cout << ' ' << config[i][i2];
				cout << endl;
				++c;
			}
		}
	}

	return 0;
}

