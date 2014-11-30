
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX_N 20001*10

int g[ MAX_N ];

#define f(n) (n*(n+1)/2)

int main() {
	int k, ans = 0;
	scanf("%d%d", g+1, &k);

	int gi, gn;
	while (scanf("%d%d", &gi, &gn) != EOF)
	{
		ans += f( g[gi] );
		while (gn--)
		{
			int i, n;
			scanf("%d%d", &i, &n);
			g[i] = n;
			ans -= f( n );
		}
	}
	printf("%d\n", ans);

	return 0;
}

