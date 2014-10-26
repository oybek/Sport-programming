
#include <cstdio>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

#define DP_SZ 10000

int denom[ 22 ], n;
long long dp[ DP_SZ ];

int main() {
	for (int i = 1; i <= 21; ++i)
		denom[i] = i*i*i;

	dp[0] = 1;
	for (int i = 1; i <= DP_SZ; ++i) {
		for (int j = 1; j <= 21; ++j)
			if (i >= denom[j])
				dp[i] += dp[ i-denom[j] ];
	}

	while (cin >> n) {
		cout << dp[n] << endl;
	}

	return 0;
}

