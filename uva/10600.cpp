
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

#define INF INT_MAX-1

#define N_MAX 101
#define M_MAX 4951

int parent[ N_MAX ];
void init_ds() { for (int i = 0; i < N_MAX; ++i) parent[i] = i; }
int find_set(int x) { return (x == parent[x] ? x : parent[x] = find_set(parent[x])); }
void union_set(int x, int y) { parent[ find_set(x) ] = parent[ find_set(y) ]; }

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
		return w < a.w;
	}

	friend
	bool operator == (const edge & a1, const edge & a2)
	{
		return (a1.a == a2.a && a1.b == a2.b);
	}
};

int N, M, mst_edges_sz;
edge edges[ M_MAX ];
edge mst_edges[ N_MAX ];

/* build mst */
int get_mst_cost()
{
	mst_edges_sz = 0;
	sort(edges, edges+M);

	int mst_cost = 0;
	for (int i = 0; i < M; ++i)
	{
		if (find_set(edges[i].a) == find_set(edges[i].b))
			continue;

		mst_cost += edges[i].w;
		mst_edges[ mst_edges_sz++ ] = edges[i];
		union_set(edges[i].a, edges[i].b);
	}

	return mst_cost;
}

/* return cost of mst ignoring one edge
 * at some cases ignoring some edge
 * can make graph not connected */
int get_mst_cost(const edge & ignore_edge)
{
	int mst_cost = 0, added_edges_num = 0;
	for (int i = 0; i < M; ++i)
	{
		if (find_set(edges[i].a) == find_set(edges[i].b) ||
			(edges[i] == ignore_edge))
			continue;

		++added_edges_num;
		mst_cost += edges[i].w;
		union_set(edges[i].a, edges[i].b);
	}

	return (added_edges_num != N-1 ? INF : mst_cost);
}

int main()
{
	int test_n;
	cin >> test_n;

	while (test_n--)
	{
		/* input phase */
		cin >> N >> M;
		for (int i = 0; i < M; ++i)
		{
			cin >> edges[i].a >> edges[i].b >> edges[i].w;
		}

		init_ds();
		cout << get_mst_cost() << ' ';

		int next_min = INF;
		for (int i = 0; i < mst_edges_sz; ++i)
		{
			init_ds();
			next_min = min(get_mst_cost(mst_edges[i]), next_min);
		}

		cout << next_min << endl;
	}

	return 0;
}

