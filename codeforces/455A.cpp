
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
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

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int main() {
	const int n_max = 100001;
	int t, t_max = 0, n, cnt[n_max];
	uint64 dp[n_max];

	fill(cnt, cnt+n_max, 0);

	cin >> n;
	while (n--) {
		cin >> t;
		t_max = max(t, t_max);
		++cnt[t];
	}

	dp[0] = 0;
	dp[1] = cnt[1];
	for (uint64 i = 2; i <= t_max; ++i)
		dp[i] = max(dp[i-1], dp[i-2]+cnt[i]*i);

	cout << dp[t_max];

	return 0;
}

