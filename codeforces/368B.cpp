
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

const int
	n_max = 10e5+2,
	val_max = 10e5+1;

int n, m, a[n_max], was[val_max], ans[n_max];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	for (int i = n; i > 0; --i) {
		ans[i] = ans[i+1] + 1-was[a[i]];
		was[a[i]] = 1;
	}

	while (m--) {
		int l;
		cin >> l;
		cout << ans[l] << endl;
	}

	return 0;
}

