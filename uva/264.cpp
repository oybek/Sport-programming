
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
	int x;
	while (cin >> x)
	{
		int diag_n
		= int(ceilf
		(
			(sqrtf(1.0+8.0*x) - 1) / 2
		));

		int count = x - (diag_n-1) * diag_n / 2 - 1;
		int a = 1;
		int b = diag_n;
		while (count--)
		{
			++a;
			--b;
		}

		printf("TERM %d is %d/%d\n", x, a, b);
	}

	return 0;
}

