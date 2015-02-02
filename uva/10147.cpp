
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

struct point
{
	int x, y;
};

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

#define N_MAX 751
#define M_MAX 280876

int parent[ N_MAX ];
void init_set()
{
	for (int i = 0; i < N_MAX; ++i)
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

int N, M;
point vertices[ N_MAX ];
vector<edge> edges;

int get_dist_sqr(const point & p1, const point & p2)
{
	return SQR(p1.x - p2.x) + SQR(p1.y - p2.y);
}

void gen_edges()
{
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			edges.push_back(edge(i, j, get_dist_sqr(vertices[i], vertices[j])));
}

void solve()
{
	gen_edges();
	sort(edges.begin(), edges.end());

	bool is_added = false;

	for (vector<edge>::iterator it = edges.begin();
		it != edges.end(); ++it)
	{
		if (find_set(it->x) == find_set(it->y))
			continue;

		is_added = true;
		cout << it->x+1 << ' ' << it->y+1 << endl;
		union_set(it->x, it->y);
	}

	if (!is_added) cout << "No new highways need\n";
}

int main()
{
	edges.reserve(M_MAX);
	int test_n;
	cin >> test_n;
	bool f = true;
	while (test_n--)
	{
		/* initialization stage */
		init_set();
		edges.resize(0);

		/* input stage */
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> vertices[i].x >> vertices[i].y;
		cin >> M;
		for (int i = 0; i < M; ++i)
		{
			int x, y;
			cin >> x >> y;
			union_set(x-1, y-1);
		}

		/* solve & output */
		if (f) f = false;
		else cout << endl;
		solve();
	}
	return 0;
}

