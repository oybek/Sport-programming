
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

#define MAX_N 1000001
#define MAX_M 1000001

struct edge
{
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax)
		, y(ay)
		, w(aw)
	{}

	bool operator < (const edge & a) const
	{
		return w < a.w;
	}
};

int N, K, M, parent[ MAX_N ], en;
edge e[ MAX_M ];

int ds_find(int x)
{
	return (x == parent[x] ? x : parent[x] = ds_find(parent[x]));
}

void ds_union(int x, int y)
{
	parent[ds_find(x)] = ds_find(y);
}

int main()
{
	int i, t;
	while (scanf("%d", &N) != EOF)
	{
		en = 0;
		for (i = 1; i <= N; ++i)
			parent[i] = i;

		for (; N--; )
			scanf("%d%d%d", &t, &t, &t);

		scanf("%d", &K);
		for (; K--; ++en)
			scanf("%d%d%d", &e[en].x, &e[en].y, &e[en].w);

		scanf("%d", &M);
		for (; M--; ++en)
			scanf("%d%d%d", &e[en].x, &e[en].y, &e[en].w);

		sort(e, e+en);
	}

	return 0;
}

