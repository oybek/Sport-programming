
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
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define x_max 501

string s;
int a[x_max][x_max], cnt[100001];

int main() {
	int x, y, x0, y0;
	cin >> x >> y >> x0 >> y0 >> s;

	for (int i = 0; i < x+1; ++i)
		fill(a[i], a[i]+y+1, s.size());

	a[x0][y0] = 0;
	for (int i = 0; i < s.size(); ++i) {
		switch (s[i]) {
			case 'U': if (x0 > 1) --x0; break;
			case 'D': if (x0 < x) ++x0; break;
			case 'L': if (y0 > 1) --y0; break;
			case 'R': if (y0 < y) ++y0; break;
		}
		a[x0][y0] = min(a[x0][y0], i+1);

	}

#ifdef DEBUG
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j)
			cout << a[i][j];
		cout << endl;
	}
	cout << endl;
#endif

	for (int i = 1; i <= x; ++i)
		for (int j = 1; j <= y; ++j)
			++cnt[a[i][j]];

	for (int i = 0; i <= s.size(); ++i)
		cout << cnt[i] << ' ';

	return 0;
}

