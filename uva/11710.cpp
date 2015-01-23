
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

	bool operator < (const edge & a) const { return w < a.w; }
};

#define vertices_sz_MAX	401
#define edges_sz_MAX	79801

int parent[ vertices_sz_MAX ];
int find_set(int x)
{
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y)
{
	parent[ find_set(x) ] = parent[ find_set(y) ];
}

int vertices_sz, edges_sz;
edge edges[ edges_sz_MAX ];

void init_set()
{
	for (int i = 0; i < vertices_sz; ++i)
		parent[i] = i;
}

int number_of_components()
{
	int count = 0;
	for (int i = 0; i < vertices_sz; ++i)
		count += (parent[i] == i);
	return count;
}

void build_graph()
{
	int count = 0, w;
	string s1, s2;
	map<string, int> code;

	for (int i = 0; i < vertices_sz; ++i)
	{
		cin >> s1;
		code[ s1 ] = count++;
	}

	for (int i = 0; i < edges_sz; ++i)
	{
		cin >> s1 >> s2 >> w;
		edges[i] = edge(code[s1], code[s2], w);
	}

	/* it is excess information */
	cin >> s1;
}

int solve()
{
	init_set();
	sort(edges, edges+edges_sz);

	int mst_cost = 0;
	for (int i = 0; i < edges_sz; ++i)
	{
		if (find_set(edges[i].x) == find_set(edges[i].y))
			continue;

		mst_cost += edges[i].w;
		union_set(edges[i].x, edges[i].y);
	}

	return (number_of_components() == 1 ? mst_cost : -1);
}

int main()
{
	while (1)
	{
		cin >> vertices_sz >> edges_sz;
		if (!vertices_sz && !edges_sz)
			break;
		build_graph();

		int ans = solve();

		if (ans == -1)
			cout << "Impossible";
		else
			cout << ans;
		cout << endl;
	}

	return 0;
}

