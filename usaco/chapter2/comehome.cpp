
/*
ID: aybek.h2
PROG: comehome
LANG: C++
*/

#define PROB_NAME "comehome"

#include <set>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <climits>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF INT_MAX

#define G_SIZE_MAX ('z'+1)

vector<pair<int, int> > G[ G_SIZE_MAX ];

// O(n)
void add_edge(int v1, int v2, int w)
{
	for (int i = 0; i < int(G[v1].size()); ++i)
		// if graph has same edge
		if (G[v1][i].first == v2)
		{
			G[v1][i].second = min(w, G[v1][i].second);

			// graph is undirected v2 v1 also must exist
			for (int j = 0; j < int(G[v2].size()); ++j)
				if (G[v2][j].first == v1)
				{
					G[v2][j].second = min(w, G[v2][j].second);
					return;
				}

			assert(0);
		}

	G[v1].push_back(make_pair(v2, w));
	G[v2].push_back(make_pair(v1, w));
}

// O(n)
int weight(int c1, int c2)
{
	for (int i = 0; i < int(G[c1].size()); ++i)
		if (G[c1][i].first == c2)
			return G[c1][i].second;

	assert(0);
}

// O(n^2)
int get_shortest_path_len(int c1, int c2)
{
	bitset<G_SIZE_MAX> visited;
	visited.reset();
	for (int i = 0; i < G_SIZE_MAX; ++i)
		visited[i] = (G[i].size() == 0);

	int dist[ G_SIZE_MAX ];
	for (int i = 0; i < G_SIZE_MAX; ++i)
		dist[i] = INF;
	dist[c1] = 0;

	while (visited.count() < G_SIZE_MAX)
	{
		int v;
		for (v = 0; visited[v]; ++v);

		for (int i = 'A'; i < G_SIZE_MAX; ++i)
			if (!visited[i] && dist[ i ] < dist[ v ])
				v = i;

		for (int i = 0; i < int(G[v].size()); ++i)
		{
			int u = G[v][i].first;

			if ((!visited[u]) &&
				(dist[ u ] > dist[ v ] + weight(v, u)))
			{
				dist[ u ] = dist[ v ] + weight(v, u);
			}
		}
		visited[v] = 1;
	}

	return dist[c2];

	return 0;
}

// O(n^3)
pair<char, int> solve()
{
	pair<char, int> ans;
	ans.second = INF;

	for (int c = 'A'; c <= 'Y'; ++c)
	{
		if (G[c].size() == 0)
			continue;

		int t = get_shortest_path_len(c, 'Z');
		if (t < ans.second)
			ans = make_pair(c, t);
	}

	return ans;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif
	int edge_n;

	cin >> edge_n;

	while (edge_n--)
	{
		int dist;
		char c1, c2;

		cin >> c1 >> c2 >> dist;

		if (c1 == c2)
			continue;

		add_edge(c1, c2, dist);
	}

	pair<char, int> ans = solve();
	printf("%c %d\n", ans.first, ans.second);

	return 0;
}

