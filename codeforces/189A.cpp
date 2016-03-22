
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

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int n, a, b, c, dp[4001];

int main() {
	cin >> n >> a >> b >> c;
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int t : { a, b, c }) {
			if (i-t < 0 || dp[i-t] == 0) continue;
			dp[i] = max(dp[i-t]+1, dp[i]);
		}
	}
	cout << dp[n]-1;

	return 0;
}

