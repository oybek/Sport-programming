
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

const int max_m = 100;
const int max_w = 25000;

int n, m, c, s, i;
int w[ max_m+1 ];
int dp[ max_m+1 ][ max_w+1 ];

int main()
{
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &m);
		s = 0;
		for (i = 1; i <= m; ++i)
		{
			scanf("%d", w+i);
			s += w[i];
		}

		int max_c = s/2;

		for (i = 1; i <= m; ++i)
			for (c = 0; c <= max_c; ++c)
				if (c < w[i])
				{
					dp[i][c] = dp[i-1][c];
				}
				else
				{
					dp[i][c] = max(dp[i-1][c], dp[i-1][c-w[i]]+w[i]);
				}

		printf("%d\n", s-2*dp[m][max_c]);
	}

	return 0;
}

