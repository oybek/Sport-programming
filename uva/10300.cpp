
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

int main()
{
	int test_n;

	scanf("%d", &test_n);
	while (test_n--)
	{
		int farmer_n, ans;

		scanf("%d", &farmer_n);
		ans = 0;
		while (farmer_n--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			ans += a*c;
		}
		printf("%d\n", ans);
	}

	return 0;
}

