
#include <set>
#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

int get_rand(int min, int max)
{
	return abs(rand())%(max-min+1) + min;
}

bool is_sorted(int * a, int n)
{
	if (n < 2)
		return true;

	for (int m = 0; m < 8; ++m)
	{
		int i = get_rand(1, n-1);
		if (a[i] < a[i-1])
			return false;
	}

	for (int i = 1; i < n; ++i)
		if (a[i] < a[i-1])
			return false;
	return true;
}

int main()
{
	srand(time(NULL));

	int n, a[ 1001 ];
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", a+i);

		int ans = 0;
		while ( ! is_sorted(a, n) )
		{
			for (int i = 1; i < n; ++i)
				if (a[i-1] > a[i])
				{
					swap(a[i-1], a[i]);
					++ans;
				}
		}
		printf("Minimum exchange operations : %d\n", ans);
	}

	return 0;
}

