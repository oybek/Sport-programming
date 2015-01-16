
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

#define SQR(x) ((x)*(x))

#define cities_size_MAX	1001
#define edges_size_MAX	500501

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
};


int edges_size,
	cities_size,
	mst_edges_size,
	road_max_len;

edge edges[ edges_size_MAX ],
	 mst_edges[ cities_size_MAX ];

pair<int, int> cities[ cities_size_MAX ];


int parent[ cities_size_MAX ];
int find_set(int x) { return (parent[x] == x ? x : parent[x] = find_set(parent[x])); }
void union_set(int x, int y) { parent[ find_set(x) ] = parent[ find_set(y) ]; }


void generate_all_edges()
{
	for (int i = 0; i < cities_size; ++i)
	{
		for (int j = i+1; j < cities_size; ++j)
		{
			edges[edges_size++] = edge(i, j,
				SQR(cities[i].first - cities[j].first) + SQR(cities[i].second - cities[j].second));
		}
	}
}

void kruskal()
{
	sort(edges, edges+edges_size);
	for (int i = 0; i < edges_size; ++i)
	{
		if (find_set(edges[i].a) == find_set(edges[i].b))
		{
			continue;
		}

		union_set(edges[i].a, edges[i].b);
		mst_edges[ mst_edges_size++ ] = edges[i];
		if (mst_edges_size == cities_size-1)
		{
			break;
		}
	}
}

int get_states_num()
{
	int railroad_num = 0;
	for (int i = 0; i < mst_edges_size; ++i)
		if (mst_edges[i].w > SQR(road_max_len))
			++railroad_num;
	return railroad_num+1;
}

int get_roads_len()
{
	double roads_len = 0;
	for (int i = 0; i < mst_edges_size; ++i)
		if (mst_edges[i].w <= SQR(road_max_len))
			roads_len += sqrtf(mst_edges[i].w);
	return static_cast<int>(round(roads_len));
}

int get_railroads_len()
{
	double roads_len = 0;
	for (int i = 0; i < mst_edges_size; ++i)
		if (mst_edges[i].w > SQR(road_max_len))
			roads_len += sqrtf(mst_edges[i].w);
	return static_cast<int>(round(roads_len));
}

int main()
{
	int test_n;
	cin >> test_n;

	for (int test_i = 1; test_i <= test_n; ++test_i)
	{
		/* initialization */
		edges_size = 0;
		mst_edges_size = 0;
		for (int i = 0; i < cities_size_MAX; ++i)
			parent[i] = i;

		/* input */
		cin >> cities_size >> road_max_len;
		for (int i = 0; i < cities_size; ++i)
		{
			cin >> cities[i].first >> cities[i].second;
		}

		/* solultion & output */
		generate_all_edges();
		kruskal();

		cout	<< "Case #" << test_i << ": "
				<< get_states_num() << ' '
				<< get_roads_len() << ' '
				<< get_railroads_len() << endl;
	}

	return 0;
}

