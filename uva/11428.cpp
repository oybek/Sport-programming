
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

#define INF INT_MAX-1

typedef unsigned long long uint64;

#define N_MAX 1000001

uint64 cubes[ N_MAX ];

int bin_search(uint64 n, int a = 0, int b = N_MAX-1)
{
	int c;
	while (a < b)
	{
		c = (a+b)/2;
		if (cubes[c] < n)
			a = c+1;
		else
		if (cubes[c] > n)
			b = c-1;
		else
			return c;
	}
	return -1;
}

int main()
{
	for (uint64 i = 0; i < N_MAX; ++i)
		cubes[i] = i*i*i;

	while (1)
	{
		int n, x, y;

		scanf("%d", &n);
		if (!n)
			break;

		bool is_any_solution = false;
		for (y = 0; uint64(y)*y*y < N_MAX; ++y)
		{
			x = bin_search(uint64(n) + uint64(y)*y*y);
			if (x != -1)
			{
				printf("%d %d\n", x, y);
				is_any_solution = true;
				break;
			}
		}
		if (!is_any_solution)
			printf("No solution\n");
	}

	return 0;
}

