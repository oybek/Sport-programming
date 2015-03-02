
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

#define grid_SIZE 10
bitset<grid_SIZE>
	grid[grid_SIZE],
	gridc[grid_SIZE];

void init_grid() {
	for (int i = 0; i < grid_SIZE; ++i)
		grid[i] = 0;
}

bool is_all_off() {
	for (int i = 0; i < grid_SIZE; ++i)
		if (gridc[i] != 0)
			return false;
	return true;
}

void do_switch(int x, int y) {
	gridc[x].flip(y);
	if (x-1 >= 0)			gridc[x-1].flip(y);
	if (x+1 < grid_SIZE)	gridc[x+1].flip(y);
	if (y-1 >= 0)			gridc[x].flip(y-1);
	if (y+1 < grid_SIZE)	gridc[x].flip(y+1);
}

int solve() {
	int switchn, switchn_min = INF;

	for (int flip = 0; flip < 1<<10; ++flip) {
		/* make copy of grid to modify */
		for (int i = 0; i < grid_SIZE; ++i)
			gridc[i] = grid[i];

		/* switching up row */
		switchn = 0;
		for (int i = 0; i < grid_SIZE; ++i)
			if (flip&(1<<i)) {
				do_switch(0, i);
				++switchn;
			}

		for (int i = 1; i < grid_SIZE; ++i)
			for (int j = 0; j < grid_SIZE; ++j)
				if (gridc[i-1][j]) {
					do_switch(i, j);
					++switchn;
				}

		if (is_all_off())
			switchn_min = min(switchn, switchn_min);
	}

	return switchn_min;
}

int main() {
	string grid_name, tstr;
	while (1) {
		/* prepare stage */
		init_grid();

		/* input stage */
		getline(cin, grid_name);
		if (grid_name == "end")
			break;
		for (int i = 0; i < grid_SIZE; ++i) {
			cin >> tstr;
			for (int j = 0; j < int(tstr.size()); ++j)
				if (tstr[j] == 'O')
					grid[i].set(j);
		}
		while (cin.get() != '\n');

		/* solution stage */
		cout << grid_name << ' ' << solve() << endl;
	}

	return 0;
}

