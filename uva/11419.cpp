
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

#define row_n_MAX 1001

int row_n, col_n, count_col[row_n_MAX], count_row[row_n_MAX];
bitset<row_n_MAX> grid[row_n_MAX];

void disable_row(int x) {
	count_row[x] = 0;
	for (int i = 0; i < col_n; ++i) {
		if (grid[x][i]) {
			grid[x][i] = 0;
			--count_col[i];
		}
	}
}

void disable_col(int x) {
	count_col[x] = 0;
	for (int i = 0; i < row_n; ++i) {
		if (grid[i][x]) {
			grid[i][x] = 0;
			--count_row[i];
		}
	}
}

int get_max_row() {
	int r = 0;
	for (int i = 1; i < row_n; ++i)
		if (count_row[i] > count_row[r])
			r = i;
	return r;
}

int get_max_col() {
	int c = 0;
	for (int i = 1; i < col_n; ++i)
		if (count_col[i] > count_col[c])
			c = i;
	return c;
}

void solve(vector<pair<char, int> > & ans) {
	while (1) {
		int c = get_max_col();
		int r = get_max_row();

		if (!count_row[r] && !count_col[c])
			break;

		if (count_col[c] > count_row[r]) {
			ans.push_back(make_pair('c', c+1));
			disable_col(c);
		} else {
			ans.push_back(make_pair('r', r+1));
			disable_row(r);
		}
	}
}

int main() {
	int enemy_n;
	vector<pair<char, int> > ans;

	while (1) {
		/* prepare stage */
		ans.resize(0);
		for (int i = 0; i < row_n_MAX; ++i)
			grid[i].reset();
		fill(count_row, count_row+row_n_MAX, 0);
		fill(count_col, count_col+row_n_MAX, 0);

		/* read stage */
		cin >> row_n >> col_n >> enemy_n;
		if (!row_n && !col_n && !enemy_n)
			break;

		while (enemy_n--) {
			int r, c;
			cin >> r >> c; --r; --c;

			++count_row[r];
			++count_col[c];
			grid[r][c] = 1;
		}

		solve(ans);
		cout << ans.size();
		for (int i = 0; i < int(ans.size()); ++i)
			cout << ' ' << ans[i].first << ans[i].second;
		cout << endl;
	}

	return 0;
}

