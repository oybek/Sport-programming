
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
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

#define N_MAX 100001

bitset<N_MAX> visited;

int N;
vector<int> G[ N_MAX ];

void bfs(int cur)
{
	queue<int> Q;
	Q.push(cur);

	while ( ! Q.empty() )
	{
		cur = Q.front(); Q.pop();
		visited[cur] = 1;

		for (int i = 0; i < int(G[cur].size()); ++i)
			if (!visited[G[cur][i]])
				Q.push(G[cur][i]);
	}
}

int solve()
{
	int comp_n = 0; /* number of components */
	for (int i = 0; i < N; ++i)
		if (!visited[i])
		{
			++comp_n;
			bfs(i);
		}
	return comp_n;
}

int main()
{
	int test_n;

	scanf("%d", &test_n);

	while (test_n--)
	{
		int M;

		scanf("%d%d", &N, &M);

		visited.reset();
		for (int i = 0; i < N; ++i)
			G[i].resize(0);

		while (M--)
		{
			int x, y;
			scanf("%d%d", &x, &y);

			--x; --y;

			G[x].push_back(y);
		}

		printf("%d\n", solve());
	}

	return 0;
}

