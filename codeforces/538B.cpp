
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
	a_sz = 1<<6+1,
	n_max = 10e6;

int n, a[a_sz], dp[n_max], last[n_max];

void gen_a() {
	for (int i = 1; i < a_sz; ++i)
		a[i] = stoi(bitset<a_sz>(i).to_string());
}

void show_a() {
	for (int i = 1; i < a_sz; ++i)
		cout << a[i] << endl;
}

int main() {
	cin >> n;

	gen_a();
	fill(dp, dp+n_max, INF);

	dp[0] = 0;
	last[0] = -1;
	for (int j = 1; j < a_sz; ++j)
		for (int i = a[j]; i <= n; ++i) {
			if (dp[i-a[j]]+1 < dp[i]) {
				dp[i] = dp[i-a[j]]+1;
				last[i] = i-a[j];
			}
		}

	cout << dp[n] << endl;
	for (int i = n; i != 0; i = last[i]) {
		cout << i-last[i] << ' ';
	}

	return 0;
}

