
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define OFFSET 128
bitset<256> was[256];

int main() {
	string s;
	int x, y;
	x = y = OFFSET;

	cin >> s;

	for (char c : s) {
		if (was[x][y]) {
			cout << "BUG";
			return 0;
		}
		if (was[x-1][y] + was[x+1][y] + was[x][y-1] + was[x][y+1] > 1) {
			cout << "BUG";
			return 0;
		}
		was[x][y] = 1;
		switch (c) {
			case 'U': --x; break;
			case 'D': ++x; break;
			case 'L': --y; break;
			case 'R': ++y; break;
		}
	}
	if (was[x][y]) {
		cout << "BUG";
		return 0;
	}
	if (was[x-1][y] + was[x+1][y] + was[x][y-1] + was[x][y+1] > 1) {
		cout << "BUG";
		return 0;
	}

	cout << "OK";
	return 0;
}

