
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

#define line_n_MAX 51

#define GOOD_COORD(x, y)\
	((x >= 0) && (y >= 0) && (x < line_n) && (y < int(grid[0].size())))

int line_n;
string grid[line_n_MAX];

bool check(const string s, int x, int y, int k1, int k2) {
	for (int i = 0; i < int(s.size()); ++i)
		if (!GOOD_COORD(x + k1*i, y + k2*i) || grid[x + k1*i][y + k2*i] != s[i])
			return false;
	return true;
}

bool is_there(const string s, int x, int y) {
	return
		check(s, x, y, -1, -1)|
		check(s, x, y, -1,  0)|
		check(s, x, y, -1, +1)|
		check(s, x, y,  0, -1)|
		check(s, x, y,  0, +1)|
		check(s, x, y, +1, -1)|
		check(s, x, y, +1,  0)|
		check(s, x, y, +1, +1);
}

pair<int, int> get_pos(const string s) {
	for (int i = 0; i < line_n; ++i)
		for (int j = 0; j < int(grid[0].size()); ++j)
			if (is_there(s, i, j))
				return make_pair(i+1, j+1);

	/* solution always exists */
	assert(false);
}

void tolower_str(string & s) {
	for (string::iterator it = s.begin(); it != s.end(); ++it)
		*it = tolower(*it);
}

int main() {
	int test_n;
	bool first = true;
	cin >> test_n;

	while (test_n--) {
		int tmp;
		cin >> line_n >> tmp;
		for (int i = 0; i < line_n; ++i) {
			cin >> grid[i];
			tolower_str(grid[i]);
		}

		int query_n;
		cin >> query_n;

		if (first) first = false;
		else cout << endl;

		while (query_n--) {
			string s;
			cin >> s;
			tolower_str(s);
			pair<int, int> pos = get_pos(s);

			cout << pos.first << ' ' << pos.second << endl;
		}
	}

	return 0;
}

