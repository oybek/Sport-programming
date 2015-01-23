
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

#define N_MAX 751
#define M_MAX 280876

#define SQR(x) ((x)*(x))

typedef unsigned int uint32;

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

int N,
	M,
	parent[ N_MAX ];

int find_set(int x) { return (x == parent[x] ? x : parent[x] = find_set(parent[x])); }
void union_set(int x, int y) { parent[ find_set(x) ] = parent[ find_set(y) ]; }

vector<pair<int, int> > vertex;
vector<edge> edges;

int get_dist_sqr(int i, int j)
{
	return SQR(vertex[i].first - vertex[j].first) + SQR(vertex[i].second - vertex[j].second);
}

double get_min_cost()
{
	double min_cost = 0;

	sort(edges.begin(), edges.end());
	for (vector<edge>::iterator it = edges.begin();
		it != edges.end();
		++it)
	{
		if (find_set(it->a) == find_set(it->b))
			continue;

		union_set(it->a, it->b);
		min_cost += sqrt(static_cast<double>(it->w));
	}

	return min_cost;
}

int main()
{
	vertex.reserve(N_MAX);
	edges.reserve(M_MAX);

	cout << fixed << setprecision(2);

	while (cin >> N)
	{
		/* initialization phase */
		edges.resize(0);
		for (int i = 0; i < N_MAX; ++i)
			parent[i] = i;

		/* input phase */
		vertex.resize(N);
		for (vector<pair<int, int> >::iterator it = vertex.begin();
			it != vertex.end();
			++it)
			cin >> it->first >> it->second;
		cin >> M;
		while (M--)
		{
			int x, y;
			cin >> x >> y;
			union_set(--x, --y);
		}

		for (uint32 i = 0; i < vertex.size(); ++i)
			for (uint32 j = i+1; j < vertex.size(); ++j)
				edges.push_back(edge(i, j, get_dist_sqr(i, j)));

		cout << get_min_cost() << endl;
	}

	return 0;
}

