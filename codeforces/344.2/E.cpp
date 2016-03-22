
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

#define n_max 200001

ll n, a[n_max], sum[n_max], c_max = LLONG_MIN;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sum[0] = a[0];
	for (int i = 1; i < n; ++i)
		sum[i] = sum[i-1] + a[i];

	ll c = 0;
	for (int i = 0; i < n; ++i)
		c += (i+1) * a[i];

	return 0;
}

