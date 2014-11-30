
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

#define DO(x, y)			\
	puts((!(x) || !(y))		\
			? "divisa"		\
			: ((x) < 0)		\
				? ((y) < 0)	\
					? "SO"	\
					: "NO"	\
				: ((y) < 0)	\
					? "SE"	\
					: "NE")	\

int main()
{
	int n, x, y, a, b;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
			break;
		scanf("%d%d", &x, &y);

		while (n--)
		{
			scanf("%d%d", &a, &b);
			DO(a-x, b-y);
		}
	}

	return 0;
}

