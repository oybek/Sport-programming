
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

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

int main()
{
	int n,
		a[ 100 ][ 100 ];

	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];

		int hn = 0,
			vn = 0,
			hi, vi;

		for (int i = 0; i < n; ++i)
		{
			int sh = 0,
				sv = 0;

			for (int j = 0; j < n; ++j)
			{
				sh += a[i][j];
				sv += a[j][i];
			}

			if (sh%2)
			{
				++hn;
				hi = i;
			}
			if (sv%2)
			{
				++vn;
				vi = i;
			}
		}

		if (hn == 1 && vn == 1)
			printf("Change bit (%d,%d)\n", vi, hi);

		if (hn == 0)
		{
			if (vn == 0)
				puts("OK");
			else
				puts("Corrupt");
		}
		else
		{
			if (vn == 0)
				puts("Corrupt");
		}
	}

	return 0;
}

