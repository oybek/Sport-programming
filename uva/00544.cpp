
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

inline void DEBUG(bool cond, const char * msg)
{
#ifdef DO_DEBUG
	if (cond)
	{
		std::cerr << msg << '\n';
		exit(0);
	}
#endif
}

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

struct edge
{
	int x, y, w;
	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}
	bool operator < (const edge & a) const
	{
		return w < a.w;
	}
};

#define vertex_sz_MAX 201
#define edges_sz_MAX 19901

unordered_map<string, int> str_id;
int vertex_sz, edges_sz;

list<pair<int, int> > G[vertex_sz_MAX];
list<pair<int, int> > mst[vertex_sz_MAX];

/* prim's algo of building mst (maximal spanning tree) */
void build_mst()
{
	bitset<vertex_sz_MAX> in_tree;
	priority_queue<edge> Q;
	edge e;

	Q.push(edge(0, 0, 0));

	int count = vertex_sz;
	while (count--)
	{
		do
		{
			e = Q.top(); Q.pop();
		} while (in_tree[e.x] && in_tree[e.y]);

		if (e.x != e.y)
		{
			mst[e.x].push_back(make_pair(e.y, e.w));
			mst[e.y].push_back(make_pair(e.x, e.w));
		}

		in_tree[e.y] = 1;

		for (list<pair<int, int> >::iterator it = G[e.y].begin();
			it != G[e.y].end(); ++it)
		{
			if (in_tree[it->first])
				continue;

			Q.push(edge(e.y, it->first, it->second));
		}
	}
}

/* returns weight of minimal edge in path from cur to dst in tree */
int get_min_on_path(int prev, int cur, int dst, int min_w)
{
	if (cur == dst)
		return min_w;

	for (list<pair<int, int> >::iterator it = mst[cur].begin();
		it != mst[cur].end(); ++it)
	{
		if (it->first == prev)
			continue;

		int t = get_min_on_path(cur, it->first, dst, min(it->second, min_w));
		if (t != -1)
			return t;
	}

	return -1;
}

int solve(int src, int dst)
{
	build_mst();
	return get_min_on_path(-1, src, dst, INF);
}

int main()
{
	for (int test_i = 1; ; ++test_i)
	{
		/* preparing stage */
		int w;
		string s1, s2;
		str_id.clear();
		for (int i = 0; i < vertex_sz_MAX; ++i)
		{
			G[i].clear();
			mst[i].clear();
		}

		/* input stage */
		cin >> vertex_sz >> edges_sz;
		if (!vertex_sz && !edges_sz)
			break;

		int id = 0;
		for (int i = 0; i < edges_sz; ++i)
		{
			cin >> s1 >> s2 >> w;

			if (str_id.find(s1) == str_id.end()) str_id.insert(make_pair(s1, id++));
			if (str_id.find(s2) == str_id.end()) str_id.insert(make_pair(s2, id++));

			G[str_id[s1]].push_back(make_pair(str_id[s2], w));
			G[str_id[s2]].push_back(make_pair(str_id[s1], w));
		}
		cin >> s1 >> s2;

		/* solve & output stage */
		cout	<< "Scenario #" << test_i << '\n'
				<< solve(str_id[s1], str_id[s2]) << " tons\n\n";
	}

	return 0;
}

