
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define n_MAX 7489
#define a_size 5

int dp[n_MAX+1],
	a[a_size] = { 1, 5, 10, 25, 50 };

int main() {
	dp[ 0 ] = 1;
	for (int i = 0; i < a_size; ++i)
		for (int j = a[i]; j <= n_MAX; ++j)
			dp[j] += dp[j-a[i]];

	int n;
	while (cin >> n)
		cout << dp[n] << endl;

	return 0;
}

