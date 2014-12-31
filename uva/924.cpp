
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

#define E_MAX 2500

int lvl_n[ E_MAX ]; /* number of elements on level */
bitset<E_MAX> was;
vector<vector<int> > G;

void bfs(int src)
{
	queue<pair<int, int> > Q;

	Q.push(make_pair(src, 0));

	while ( !Q.empty() )
	{
		pair<int, int> t = Q.front(); Q.pop();

		was[t.first] = 1;
		++lvl_n[ t.second ];

		for (int i = 0; i < int(G[t.first].size()); ++i)
			if (!was[ G[t.first][i] ])
				Q.push(make_pair(G[t.first][i], t.second+1));
	}
}

int main()
{
	int E;

	G.reserve(E_MAX);

	scanf("%d", &E);

	G.resize(E);

	for (int i = 0; i < E; ++i)
	{
		int friends_n;

		scanf("%d", &friends_n);

		while (friends_n--)
		{
			int j;
			scanf("%d", &j);

			G[i].push_back(j);
			/*G[j].push_back(i);*/
		}
	}

	int test_n;

	scanf("%d", &test_n);

	while (test_n--)
	{
		int src;

		scanf("%d\n", &src);

		fill(lvl_n, lvl_n+E, 0);
		was.reset();
		bfs(src);

		int max_i = 0;
		for (int i = 1; i < E; ++i)
			if (lvl_n[max_i] < lvl_n[i])
				max_i = i;

		if (max_i == 0)
			puts("0");
		else
			printf("%d %d\n", lvl_n[max_i], max_i);
	}

	return 0;
}

