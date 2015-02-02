
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

inline void DEBUG(bool cond, const char * msg) {
#ifdef DO_DEBUG
	if (cond) {
		std::cerr << msg << '\n';
		exit(0);
	}
#endif
}

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

#define N_MAX 101

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	/* building maximal spanning tree */
	bool operator < (const edge & a) const {
		return w < a.w;
	}
};

int N, R, S, D, T;
list<pair<int, int> > G[N_MAX], mst[N_MAX];

void build_mst() {
	edge e;
	bitset<N_MAX> in_tree; in_tree.reset();
	priority_queue<edge> Q;

	Q.push(edge(0, 0, 0));
	for (int i = 0; i < N; ++i) {
		do {
			DEBUG(Q.empty(), "build_mst(): graph is not connected.");
			e = Q.top(); Q.pop();
		} while (in_tree[e.x] && in_tree[e.y]);

		if (e.x != e.y) {
			mst[e.x].push_back(make_pair(e.y, e.w));
			mst[e.y].push_back(make_pair(e.x, e.w));
		}

		in_tree[e.y] = 1;

		for (
			list<pair<int, int> >::const_iterator it = G[e.y].begin();
			it != G[e.y].end();
			++it
		) {
			if (in_tree[it->first]) continue;
			Q.push(edge(e.y, it->first, it->second));
		}
	}
}

/* returns the length of the minimal edge on path from cur to dst in mst */
int get_min_on_path(int prev, int cur, int dst, int min_w)
{
	if (cur == dst) {
		return min_w;
	}

	for (
		list<pair<int, int> >::const_iterator it = mst[cur].begin();
		it != mst[cur].end();
		++it
	) {
		if (it->first == prev) continue;
		int t = get_min_on_path(cur, it->first, dst, min(it->second, min_w));
		if (t != -1)
			return t;
	}

	return -1;
}

int solve() {
	build_mst();
	int t = get_min_on_path(-1, D, S, INF);
	return T / t + (T % t ? 1: 0);
}

int main() {
	for (int test_i = 1; ; ++test_i) {
		/* prepare phase */
		for (int i = 0; i < N_MAX; ++i) {
			G[i].clear();
			mst[i].clear();
		}

		/* input */
		cin >> N >> R;
		if (!N && !R) break;
		while (R--) {
			int x, y, w;
			cin >> x >> y >> w; --x, --y;
			--w; /* the tourist guide itself */
			G[x].push_back(make_pair(y, w));
			G[y].push_back(make_pair(x, w));
		}
		cin >> S >> D >> T; --S, --D;

		/* solution phase */
		cout	<< "Scenario #" << test_i
				<< "\nMinimum Number of Trips = " << solve() << "\n\n";
	}

	return 0;
}

