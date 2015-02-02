
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

#ifdef DO_DEBUG
	#define debug(x) std::cerr << x << '\n'
#else
	#define debug(x)
#endif

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

struct edge
{
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax) , y(ay) , w(aw)
	{}

	bool operator < (const edge & a) const
	{
		return w > a.w;
	}
};

#define n_MAX 101
#define m_MAX 10001

int parent[ n_MAX ];
void init_set()
{
	for (int i = 0; i < n_MAX; ++i)
		parent[i] = i;
}
int find_set(int x)
{
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y)
{
	parent[ find_set(x) ] = parent[ find_set(y) ];
}

int n, m, test_n, test_i;
edge edges[ m_MAX ];
vector<edge> hst_edges;

int solve() /* heaviest spanning tree */
{
	int min_w = INF;

	sort(edges, edges+m);
	for (int i = 0; i < m; ++i)
	{
		if (find_set(edges[i].x) == find_set(edges[i].y))
			continue;

		min_w = min(edges[i].w, min_w);
		union_set(edges[i].x, edges[i].y);
	}
	return min_w;
}

int main()
{
	hst_edges.reserve(n_MAX);

	cin >> test_n;
	for (test_i = 1; test_i <= test_n; ++test_i)
	{
		/* initialization */
		init_set();
		hst_edges.resize(0);

		/* input */
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
			cin >> edges[i].x >> edges[i].y >> edges[i].w;

		cout << "Case #" << test_i << ": " << solve() << endl;
	}

	return 0;
}

