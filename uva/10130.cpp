
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define MAX_N 1000
#define MAX_P 100
#define MAX_W 30

int T, N, G, W,
	p[ MAX_N+1 ],
	w[ MAX_N+1 ],
	dp[ MAX_N+1 ][ MAX_W+1 ];

void reset_dp()
{
	for (int i = 0; i <= MAX_N; ++i)
		dp[i][0] = 0;
	for (int i = 0; i <= MAX_W; ++i)
		dp[0][i] = 0;
}

int main()
{
	int ans;

	scanf("%d", &T);
	while (T--)
	{
		reset_dp();

		scanf("%d", &N);
		for (int i = 1; i <= N; ++i)
			scanf("%d%d", p+i, w+i);

		ans = 0;

		scanf("%d", &G);
		while (G--)
		{
			scanf("%d", &W);
			for (int k = 1; k <= N; ++k)
			for (int s = 1; s <= W; ++s)
				if (s < w[k])
					dp[k][s] = dp[k-1][s];
				else
					dp[k][s] = max( dp[k-1][s], dp[k-1][s-w[k]] + p[k] );

			ans += dp[N][W];
		}
		printf("%d\n", ans);
	}

	return 0;
}

