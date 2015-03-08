
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
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define n_MAX 10001
#define a_sz 10

int dp[n_MAX],
	a[a_sz] = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000 };

#define EPS 0.001

int main() {
	dp[0] = 1;
	for (int i = 0; i < a_sz; ++i) {
		for (int j = a[i]; j < n_MAX; ++j) {
			dp[j] += dp[j-a[i]];
		}
	}

	float t;
	while (cin >> t) {
		if (t < EPS)
			break;

		cout	<< fixed << setprecision(2) << setw(5) << t
				<< setw(12) << dp[int(t*100)/5] << endl;
	}

	return 0;
}

