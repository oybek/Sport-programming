
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	const int n_max = 100001;
	int n, a[n_max], dp[n_max], ans = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	dp[0] = 1;
	for (int i = 1; i < n; ++i)
		dp[i] = a[i-1] <= a[i] ? dp[i-1]+1 : 1;

	cout << *max_element(dp, dp+n) << endl;

	return 0;
}

