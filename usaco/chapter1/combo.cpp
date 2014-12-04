
/*
ID: aybek.h2
PROG: combo
LANG: C++
*/

#define PROB_NAME "combo"

#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
using namespace std;

#define dist(a, b, n) min(abs((a)-(b)), ((n)-abs((a)-(b))))

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	int N,
		a1, a2, a3,
		b1, b2, b3,
		count = 0;

	scanf("%d", &N);
	scanf("%d%d%d", &a1, &a2, &a3);
	scanf("%d%d%d", &b1, &b2, &b3);

	for (int i1 = 1; i1 <= N; ++i1)
	for (int i2 = 1; i2 <= N; ++i2)
	for (int i3 = 1; i3 <= N; ++i3)
	{
		count +=
		(
			(
				(dist(i1, a1, N) <= 2) &&
				(dist(i2, a2, N) <= 2) &&
				(dist(i3, a3, N) <= 2)
			)
			||
			(
				(dist(i1, b1, N) <= 2) &&
				(dist(i2, b2, N) <= 2) &&
				(dist(i3, b3, N) <= 2)
			)
		);
	}

	printf("%d\n", count);

	return 0;
}

