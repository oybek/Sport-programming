
#include <cstdio>
#include <vector>
#include <cctype>
#include <climits>
#include <iostream>
using namespace std;

int main()
{
	int test_n;
	int a[ 1001 ];

	scanf("%d", &test_n);

	while (test_n--)
	{
		int n, k;
		scanf("%d%d", &n, &k);

		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);

		int ans = INT_MIN;
		for (int mask = 0; mask < (1<<n); ++mask)
		{
			int f = k;
			for (int i = 0; i < n; ++i)
				if (mask & (1<<i))
					f ^= a[i];

			ans = max(f, ans);
		}

		printf("%d\n", ans);
	}

	return 0;
}

