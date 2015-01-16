
#include <set>
#include <map>
#include <list>
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

#define vertex_num_MAX 101

struct edge
{
	int a, b, w;

	edge(int aa = 0, int ab = 0, int aw = 0)
		: a(aa)
		, b(ab)
		, w(aw)
	{}

	bool operator < (const edge & a) const
	{
		return !(w < a.w);
	}
};

int edge_num,
	vertex_num,
	queries_num;

list<pair<int, int> >
	mst[ vertex_num_MAX ],
	graph[ vertex_num_MAX ];

void build_mst()
{
	bitset<vertex_num_MAX> in_tree;
	priority_queue<edge> Q;

	edge e;
	in_tree.reset();

	for (int i = 0; i < vertex_num; ++i)
	{
		do
		{
			/* new component */
			if (Q.empty())
			{
				for (int i = 0; i < vertex_num; ++i)
					if (!in_tree[i])
					{
						Q.push(edge(i, i, 0));
						break;
					}
			}
			if (Q.empty()) return;
			e = Q.top(); Q.pop();
		} while (in_tree[e.a] && in_tree[e.b]);

		if (e.a != e.b)
		{
			mst[ e.a ].push_back(make_pair(e.b, e.w));
			mst[ e.b ].push_back(make_pair(e.a, e.w));
		}

		in_tree[ e.b ] = 1;

		for (list<pair<int, int> >::const_iterator it = graph[ e.b ].begin();
			it != graph[ e.b ].end(); ++it)
		{
			if (in_tree[ it->first ]) continue;
			Q.push(edge(e.b, it->first, it->second));
		}
	}
}

bitset<vertex_num_MAX> visited;
int dfs(int a, int b, int max_w)
{
	if (visited[a])
		return -1;
	visited[a] = 1;

	if (a == b)
		return max_w;

	for (list<pair<int, int> >::iterator it = mst[a].begin();
		it != mst[a].end(); ++it)
	{
		int tmp = dfs(it->first, b, max(max_w, it->second));
		if (tmp != -1)
			return tmp;
	}
	return -1;
}

int main()
{
	bool f = true;
	for (int test_i = 1; true; ++test_i)
	{
		/* initialization */
		for (int i = 0; i < vertex_num_MAX; ++i)
		{
			mst[i].clear();
			graph[i].clear();
		}

		/* building graph */
		cin >> vertex_num >> edge_num >> queries_num;
		if (!vertex_num && !edge_num && !queries_num)
			break;

		for (int i = 0; i < edge_num; ++i)
		{
			int a, b, w;
			cin >> a >> b >> w;

			--a; --b;

			graph[a].push_back(make_pair(b, w));
			graph[b].push_back(make_pair(a, w));
		}

		/* builds mst forest */
		build_mst();

		/* handling queries */
		if (f) f = false;
		else cout << endl;
		cout << "Case #" << test_i << endl;
		while (queries_num--)
		{
			int a, b;
			cin >> a >> b;
			--a; --b;

			visited.reset();
			int ans = dfs(a, b, -1);
			if (ans == -1)
				cout << "no path\n";
			else
				cout << ans << endl;
		}
	}

	return 0;
}

