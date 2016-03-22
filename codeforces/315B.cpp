
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

int n, m;
ll add, a[n_max];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (; m--; ) {
		int com;
		cin >> com;
		switch (com) {
			case 1:
				int i, v;
				cin >> i >> v; --i;
				a[i] = v-add;
				break;
			case 2:
				cin >> v;
				add += v;
				break;
			case 3:
				cin >> i; --i;
				cout << a[i] + add << endl;
				break;
		}
	}

	return 0;
}

