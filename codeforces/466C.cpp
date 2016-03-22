
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

const int n_max = 5*10e5+1;
int n, a[n_max], dp[n_max];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	ll sum = accumulate(a, a+n, 0);
	if (sum%3) {
		cout << 0 << endl;
	} else {
		int sum3 = sum/3;
	}

	return 0;
}

