
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

#define n_max 100000

#define CHECK if (--m == 0) return

ll n, m, v;
vector<vector<int> > G;

void solve(int m) {
	if (v == 1) {
		cout << v << " 3" << endl; CHECK;
		cout << v << " 2" << endl; CHECK;

		for (int i = 3; i < n; ++i) {
			cout << i << ' ' << i+1 << endl; CHECK;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i+2; j <= n; ++j) {
				if (i == 2) break;
				if (j == 2) continue;
				if (m == 0) return;

				cout << i << ' ' << j << endl; CHECK;
			}
		}
	} else {
		cout << v << " 1" << endl; CHECK;
		for (int i = 2; i < n; ++i) {
			cout << i << ' ' << i+1 << endl; CHECK;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = i+2; j <= n; ++j) {
				if (i == 1) break;
				if (j == 1) continue;
				if (m == 0) return;

				cout << i << ' ' << j << endl; CHECK;
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	ll max_edge_possible = (n-1)*(n-2)/2 + 1;

	if (max_edge_possible < m || m < n-1) {
		cout << -1;
		return 0;
	} else {
		solve(m);
	}

	return 0;
}

