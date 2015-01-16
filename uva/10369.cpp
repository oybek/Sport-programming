
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

#define outposts_num_MAX 501
#define edges_num_MAX 124751

int parent[ outposts_num_MAX ];
int find_set(int x) { return x == parent[x] ? x : parent[x] = find_set(parent[x]); }
void union_set(int x, int y) { parent[find_set(x)] = parent[find_set(y)]; }

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

int satellites_num, outposts_num, edges_num;
pair<int, int> outposts[ outposts_num_MAX ];
edge edges[ edges_num_MAX ];

int get_dist_sqr(const pair<int, int> & a1, const pair<int, int> & a2)
{
	return SQR(a1.first - a2.first) + SQR(a1.second - a2.second);
}

int get_mst_max_edge()
{
	sort(edges, edges+edges_num);

	int max_edge_weight = 0, count = (outposts_num-1) - (satellites_num-1);

	edge * e = edges;
	while (count--)
	{
		while (find_set(e->a) == find_set(e->b))
			++e;

		max_edge_weight = max(e->w, max_edge_weight);
		union_set(e->a, e->b);
	}

	return max_edge_weight;
}

int main()
{
	int test_n;
	cout << fixed << setprecision(2);

	cin >> test_n;
	while (test_n--)
	{
		/* initialization */
		edges_num = 0;
		for (int i = 0; i < outposts_num_MAX; ++i)
			parent[i] = i;

		/* input */
		cin >> satellites_num >> outposts_num;
		for (int i = 0; i < outposts_num; ++i)
			cin >> outposts[i].first >> outposts[i].second;

		for (int i = 0; i < outposts_num; ++i)
			for (int j = i+1; j < outposts_num; ++j)
				edges[ edges_num++ ] = edge(i, j, get_dist_sqr(outposts[i], outposts[j]));

		cout << sqrtf(get_mst_max_edge()) << endl;
	}

	return 0;
}

