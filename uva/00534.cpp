
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

#define stones_num_MAX 201

struct edge
{
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}


	bool operator < (const edge & a) const
	{
		return !(w < a.w);
	}
};

int stones_size;
pair<int, int> stones[ stones_num_MAX ];
list<pair<int, int> > mst[ stones_num_MAX ], G[ stones_num_MAX ];

int get_dist_sqr(int i, int j)
{
	return SQR(stones[i].first - stones[j].first) + SQR(stones[i].second - stones[j].second);
}

void build_mst()
{
	bitset<stones_num_MAX> in_tree;
	priority_queue<edge> Q;
	edge e;
	in_tree.reset();

	Q.push(edge(0, 0, 0));
	/* in each iteration we add one vertex to MST */
	for (int i = 0; i < stones_size; ++i) {
		do {
			if (Q.empty()) assert(false);
			e = Q.top(); Q.pop();
		} while (in_tree[e.x] && in_tree[e.y]);

		if (e.x != e.y) {
			mst[ e.x ].push_back(make_pair(e.y, e.w));
			mst[ e.y ].push_back(make_pair(e.x, e.w));
		}

		in_tree[ e.y ] = 1;

		for (
			list<pair<int, int> >::const_iterator it = G[ e.y ].begin();
			it != G[ e.y ].end();
			++it
		) {
			if (in_tree[ it->first ]) continue;
			Q.push(edge(e.y, it->first, it->second));
		}
	}
}

/* return the weight of the maximal edge in mst in path from cur to dst */
int get_max_on_path(int prev, int cur, int dst, int max_w)
{
	if (cur == dst)
		return max_w;

	for
	(
		list<pair<int, int> >::const_iterator it = mst[cur].begin();
		it != mst[cur].end();
		++it
	)
	{
		if (it->first == prev)
			continue;

		int tmp = get_max_on_path(cur, it->first, dst, max(it->second, max_w));
		if (tmp != -1)
			return tmp;
	}

	return -1;
}

float solve()
{
	/* gen graph */
	for (int i = 0; i < stones_size; ++i)
		for (int j = i+1; j < stones_size; ++j)
		{
			G[i].push_back(make_pair(j, get_dist_sqr(i, j)));
			G[j].push_back(make_pair(i, get_dist_sqr(i, j)));
		}

	build_mst();

	return sqrtf(get_max_on_path(-1, 0, 1, 0));
}

int main()
{
	cout << fixed << setprecision(3);
	for (int test_i = 1; ; ++test_i)
	{
		/* initialization */
		for (int i = 0; i < stones_num_MAX; ++i)
		{
			mst[i].clear();
			G[i].clear();
		}

		/* input phase */
		cin >> stones_size;
		if (!stones_size)
			break;
		for (int i = 0; i < stones_size; ++i)
			cin >> stones[i].first >> stones[i].second;

		cout	<< "Scenario #" << test_i
				<< "\nFrog Distance = " << solve() << "\n\n";
	}

	return 0;
}

