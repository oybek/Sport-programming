
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

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

#define vertex_sz_MAX 502
#define edges_sz_MAX 125251

struct edge {
	int x, y, w;

	edge(int ax = 0, int ay = 0, int aw = 0)
		: x(ax), y(ay), w(aw)
	{}

	bool operator < (const edge & a) const {
		return w < a.w;
	}
};

int parent[vertex_sz_MAX];
void init_set() {
	for (int i = 0; i < vertex_sz_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

int vertex_sz;
bool is_zero_key; /* 0000 may be one of the keys */
string vertex[vertex_sz_MAX];
vector<edge> edges;

int get_roll_num(const string & s1, const string & s2) {
	assert(s1.size() == s2.size());
	int roll_num = 0;
	for (int i = 0; i < int(s1.size()); ++i) {
		roll_num += min(abs(s1[i]-s2[i]), 10-abs(s1[i]-s2[i]));
	}
	return roll_num;
}

/* returns the cost of mst */
int build_mst() {
	sort(edges.begin(), edges.end());
	init_set();

	int mst_cost = 0, count = vertex_sz-1;
	for (vector<edge>::iterator it = edges.begin(); count && it != edges.end(); ++it) {
		if (find_set(it->x) == find_set(it->y))
			continue;

		union_set(it->x, it->y);
		mst_cost += it->w;
		--count;
	}

	/* add shortest edge from "0000" to mst */
	int t = 0;
	if (!is_zero_key) {
		t = INF;
		for (int i = 0; i < vertex_sz; ++i) {
			t = min(get_roll_num("0000", vertex[i]), t);
		}
	}

	return mst_cost + t;
}

int main() {
	int test_n;
	edges.reserve(edges_sz_MAX);

	cin >> test_n;
	while (test_n--) {
		/* prepare stage */
		is_zero_key = false;
		edges.resize(0);

		/* input */
		cin >> vertex_sz;
		for (int i = 0; i < vertex_sz; ++i) {
			cin >> vertex[i];
			if (vertex[i] == "0000")
				is_zero_key = true;
		}

		/* solve and output */
		/* generate all edges */
		for (int i = 0; i < vertex_sz; ++i) {
			for (int j = i+1; j < vertex_sz; ++j) {
				edges.push_back(edge(i, j, get_roll_num(vertex[i], vertex[j])));
			}
		}
		cout << build_mst() << endl;
	}

	return 0;
}

