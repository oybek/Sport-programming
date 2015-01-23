
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

using namespace std;

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

#define points_size_MAX 101

struct point
{
	double x, y;
};

struct edge
{
	int a, b;
	double w;

	edge(int aa, int ab, double aw)
		: a(aa)
		, b(ab)
		, w(aw)
	{}

	bool operator < (const edge & a) const
	{
		return w < a.w;
	}
};

int parent[ points_size_MAX ];
int find_set(int x)
{
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y)
{
	parent[ find_set(x) ] = parent[ find_set(y) ];
}

int points_size; /* number of points */
point points[ points_size_MAX ];

double dist(int i, int j)
{
	return sqrt(SQR(points[i].x-points[j].x) + SQR(points[i].y-points[j].y));
}

/* Kruskal of course */
double solve()
{
	vector<edge> edges;

	/* generate all possible edges */
	for (int i = 0; i < points_size; ++i)
		for (int j = i+1; j < points_size; ++j)
			edges.push_back(edge(i, j, dist(i, j)));

	sort(edges.begin(), edges.end());

	double mst_cost = 0.0;
	for (vector<edge>::const_iterator it = edges.begin();
		it != edges.end(); ++it)
	{
		if (find_set(it->a) == find_set(it->b))
			continue;

		mst_cost += it->w;
		union_set(it->a, it->b);
	}

	return mst_cost;
}

int main()
{
	int test_n;
	cin >> test_n;

	cout << fixed << setprecision(2);

	bool f = true;
	while (test_n--)
	{
		/* preparing */
		for (int i = 0; i < points_size_MAX; ++i)
			parent[i] = i;

		/* input */
		cin >> points_size;
		for (int i = 0; i < points_size; ++i)
		{
			cin >> points[i].x >> points[i].y;
		}

		/* we got array of points, goal is to count cost of MST */

		if (f) f = false;
		else cout << endl;
		cout << solve() << endl;
	}

	return 0;
}

