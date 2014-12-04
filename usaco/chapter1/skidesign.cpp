
/*
ID: aybek.h2
PROG: skidesign
LANG: C++
*/

#define PROB_NAME "skidesign"

#include <vector>
#include <climits>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define sqr(n) ((n)*(n))

#define MAX_VAL 100

typedef long long int64;

int q[ MAX_VAL+1 ];

int64 count_cost(const int * q, int b1, int b2)
{
	int cost = 0;

	for (int i = 0; i < b1; ++i)
		cost += q[i] * sqr(b1 - i);

	for (int i = MAX_VAL; i > b2; --i)
		cost += q[i] * sqr(b2 - i);

	return cost;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif
	fill(q, q+MAX_VAL+1, 0);

	int n;
	scanf("%d", &n);
	while (n--)
	{
		int t;
		scanf("%d", &t);
		++q[t];
	}

	int64 min_cost = LONG_MAX;
	for (int i = 0; i+17 <= MAX_VAL; ++i)
	{
		min_cost = min(count_cost(q, i, i+17), min_cost);
	}
	printf("%lld\n", min_cost);

	return 0;
}

