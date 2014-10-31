
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

int main()
{
	static const int size = 101;
	int n, t;
	register int c[ size ];

	while (1)
	{
		fill(c, c+size, 0);

		scanf("%d", &n);
		if (!n)
			break;

		while (n--) {
			scanf("%d", &t);
			++c[t];
		}

		bool first = true;
		for_(int, i, 0, size)
	   		while (c[i]--)
			{
				if (first) first = false;
				else putchar(' ');
				printf("%d", i);
			}
		puts("");
	}

	return 0;
}

