
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

#define n_max 1001

ull n, a[n_max], b[n_max], as[n_max], bs[n_max], ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];

	as[1] = a[1];
	bs[1] = b[1];
	for (int i = 2; i <= n; ++i) as[i] = as[i-1] | a[i];
	for (int i = 2; i <= n; ++i) bs[i] = bs[i-1] | b[i];

	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			ans = max(ans, (as[j]|as[i-1])+(bs[j]|bs[i-1]));

	cout << ans;

	return 0;
}

