
/*
ID: aybek.h2
PROG: inflate
LANG: C++
*/

#define PROB_NAME "inflate"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define M_MAX 10001
#define N_MAX 10001

int M, N, dp[M_MAX];
pair<int, int> a[N_MAX];

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	cin >> M >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i].first >> a[i].second;
	}

	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = a[i].second; j <= M; ++j) {
			dp[j] = max(dp[j-a[i].second] + a[i].first, dp[j]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= M; ++i)
		ans = max(dp[i], ans);
	cout << ans << endl;

	return 0;
}

