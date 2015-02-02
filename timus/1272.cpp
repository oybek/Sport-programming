
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

#define N_MAX 10001
#define K_MAX 12001
#define M_MAX 12001

int parent[N_MAX];
void init_set() {
	for (int i = 0; i < N_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

int N, K, M;

int main() {
	int min_bridge_num, x, y;
	init_set();

	cin >> N >> K >> M;

	min_bridge_num = 0;
	while (K--) {
		cin >> x >> y;
		union_set(x, y);
	}
	while (M--) {
		cin >> x >> y;
		if (find_set(x) != find_set(y)) {
			++min_bridge_num;
			union_set(x, y);
		}
	}
	cout << min_bridge_num << endl;

	return 0;
}

