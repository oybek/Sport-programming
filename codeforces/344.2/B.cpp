
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

#define n_max 5001
int n, m, k;
pair<int, int> r[n_max], c[n_max]; /* color, time */

int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		int t, ri, ci, color;
		cin >> t;
		switch (t) {
			case 1:
				cin >> ri >> color; --ri;
				r[ri].first = color;
				r[ri].second = i;
				break;
			case 2:
				cin >> ci >> color; --ci;
				c[ci].first = color;
				c[ci].second = i;
				break;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (r[i].second > c[j].second) {
				cout << r[i].first;
			} else {
				cout << c[j].first;
			}
			cout << ' ';
		}
		cout << endl;
	}

	return 0;
}

