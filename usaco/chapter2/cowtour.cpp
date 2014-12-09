
/*
ID: aybek.h2
PROG: cowtour
LANG: C++
*/

#define PROB_NAME "cowtour"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 150

#define sqr(x) ((x)*(x))

#define INF 200000000000.0f

typedef long long int64;

int N;
double dist[ N_MAX+1 ][ N_MAX+1 ];
vector<pair<int, int> > point;

namespace debug
{
	void show_dist()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (dist[i][j] == INF)
					printf("%10s", "INF");
				else
					printf("%10f", dist[i][j]);
			}
			puts("");
		}
	}
};

double get_dist(pair<int, int> a, pair<int, int> b)
{
	return sqrtf(sqr(a.first - b.first) + sqr(a.second - b.second));
}

void floyd_warshall()
{
	for (int k = 0; k < N; ++k)
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
}

/* get's longest path beginning in from */
double get_longest(int from)
{
	double longest = 0;
	for (int i = 0; i < N; ++i)
		if (dist[from][i] != INF && dist[from][i] > longest)
			longest = dist[from][i];
	return longest;
}

double solve()
{
	double ans = INF;
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
	{
		if (dist[i][j] == INF)
		{
			double dist
				= get_longest(i)
				+ get_dist(point[i], point[j])
				+ get_longest(j);

			if (dist < ans)
				ans = dist;
		}
	}
	return ans;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	double d;
	char s[ N_MAX ];

	scanf("%d", &N);
	point.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d%d", &(point[i].first), &(point[i].second));

	for (int i = 0; i < N; ++i)
	{
		scanf("%s", s);

		for (int j = i+1; j < N; ++j)
		{
			switch (s[j])
			{
				case '1':
					d = get_dist(point[i], point[j]);
					dist[i][j] = d;
					dist[j][i] = d;
					break;

				case '0':
					dist[i][j] = INF;
					dist[j][i] = INF;
					break;
			}
		}
		dist[i][i] = 0.0;
	}

	floyd_warshall();
	double ans = solve();
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		if (dist[i][j] != INF && dist[i][j] > ans)
			ans = dist[i][j];
	printf("%.6f\n", ans);

/*#ifdef LOCAL*/
	/*debug::show_dist();*/
/*#endif*/

	return 0;
}

