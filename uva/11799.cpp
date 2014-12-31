
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

#define INF INT_MAX

int main()
{
	int test_n, N, max_speed, t;

	scanf("%d", &test_n);
	for (int test_i = 1; test_i <= test_n; ++test_i)
	{
		max_speed = -INF;

		scanf("%d", &N);

		while (N--)
		{
			scanf("%d", &t);
			max_speed = max(t, max_speed);
		}

		printf("Case %d: %d\n", test_i, max_speed);
	}

	return 0;
}

