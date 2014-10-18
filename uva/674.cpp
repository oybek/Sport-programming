
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 7489
#define centn 5

#define DP(i) ((i) < 0 ? 0: dp[i])

int dp[ maxn+1 ],
	cent[ centn ] = { 1, 5, 10, 25, 50 };

int main() {
	int i, j, n;

	dp[ 0 ] = 1;
	for (j = 0; j < centn; ++j) {
		for (i = 1; i <= 7489; ++i) {
			dp[i] += DP(i - cent[j]);
		}
	}

	while ( cin >> n ) {
		cout << dp[n] << endl;
	}

	return 0;
}

