
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

#define N_MAX 10001
#define M_MAX 100001

int parent[ N_MAX ];
int find_set(int x)
{
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y)
{
	parent[ find_set(x) ] = parent[ find_set(y) ];
}

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

/* number of cities, number of roads, aiport building cost */
int N, M, A;
edge edges[ M_MAX ];

void init_set()
{
	for (int i = 0; i < N_MAX; ++i)
		parent[i] = i;
}

int get_components_num()
{
	int count = 0;
	for (int i = 0; i < N; ++i)
		count += (parent[i] == i);
	return count;
}

void solve(int & roads_cost, int & airport_num)
{
	/* build MST */
	vector<edge> mst_edges;
	sort(edges, edges+M);
	for (int i = 0; i < M; ++i)
	{
		if (find_set(edges[i].x) == find_set(edges[i].y))
			continue;

		roads_cost += edges[i].w;
		mst_edges.push_back(edges[i]);
		union_set(edges[i].x, edges[i].y);
	}

	airport_num = get_components_num();
	for (vector<edge>::const_reverse_iterator it = mst_edges.rbegin();
		it != mst_edges.rend(); ++it)
	{
		if (it->w < A)
			break;

		roads_cost -= it->w;
		++airport_num;
	}
}

int main()
{
	int test_n,
		roads_cost,
		airport_num;

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i)
	{
		/* preparing stage */
		init_set();

		/* input stage */
		cin >> N >> M >> A;
		for (int i = 0; i < M; ++i)
		{
			cin >> edges[i].x >> edges[i].y >> edges[i].w;
			edges[i].x--;
			edges[i].y--;
		}

		/* solution stage */
		solve(roads_cost = 0, airport_num);

		cout	<< "Case #" << test_i << ": "
				<< roads_cost + airport_num*A << ' ' << airport_num << endl;
	}

	return 0;
}

