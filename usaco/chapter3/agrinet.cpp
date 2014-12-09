
/*
ID: aybek.h2
PROG: agrinet
LANG: C++
*/

#define PROB_NAME "agrinet"

#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 100

int N,
	weight[N_MAX][N_MAX];
bitset<N_MAX> connected;

int solve()
{
	int s = 0;

	priority_queue<pair<int,int> > Q;
	Q.push(make_pair(0 ,0));

	while (! Q.empty())
	{
		pair<int, int> t = Q.top(); Q.pop();
		connected[t.second] = 1;
		s += t.first;

		for (int i = 0; i < N; ++i)
			if (!connected[i])
				Q.push(make_pair(-weight[t.second][i], i));

		while (!Q.empty() && connected[ Q.top().second ])
			Q.pop();
	}
	return s;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	connected.reset();

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		scanf("%d", &(weight[i][j]));

	printf("%d\n", abs(solve()));

	return 0;
}

