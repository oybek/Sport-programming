
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1

#define N_MAX 1000001

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

int parent[ N_MAX ];
int find_set(int x) { return (x == parent[x] ? x : parent[x] = find_set(parent[x])); }
void union_set(int x, int y) { parent[ find_set(x) ] = parent[ find_set(y) ]; }

int N, K, M, a, b, w;
vector<edge> edges;

int get_min_mst_cost()
{
	sort(edges.begin(), edges.end());

	int min_cost = 0, count = N-1;
	for (vector<edge>::const_iterator it = edges.begin();
		it != edges.end() && count > 0;
		++it)
	{
		if (find_set(it->a) == find_set(it->b))
			continue;

		--count;
		min_cost += it->w;
		union_set(it->a, it->b);
	}

	return min_cost;
}

int main()
{
	bool f = true;
	edges.reserve(2000000);

	while (cin >> N)
	{
		/* initialization */
		edges.clear();
		int initial_cost = 0;
		for (int i = 0; i < N_MAX; ++i)
			parent[i] = i;

		/* input */
		for (int i = 1; i < N; ++i)
		{
			cin >> a >> b >> w;
			initial_cost += w;
		}

		cin >> K;
		while (K--)
		{
			cin >> a >> b >> w;
			edges.push_back(edge(a, b, w));
		}

		cin >> M;
		while (M--)
		{
			cin >> a >> b >> w;
			edges.push_back(edge(a, b, w));
		}

		if (f) f = false; else cout << endl;
		cout	<< initial_cost << endl
				<< get_min_mst_cost() << endl;
	}

	return 0;
}

