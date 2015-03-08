
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

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define N_MAX 30001

int parent[N_MAX], size[N_MAX];
void init_set() {
	for (int i = 0; i < N_MAX; ++i) {
		parent[i] = i;
		size[i] = 1;
	}
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void join_set(int x, int y) {
	if (find_set(x) == find_set(y)) return;
	size[find_set(y)] += size[find_set(x)];
	parent[find_set(x)] = parent[find_set(y)];
}
int get_max(int * a, int * b) {
	int t = -1;
	for (; a != b; ++a)
		t = max(*a, t);
	return t;
}

int N, M;

int main() {
	int test_n;
	cin >> test_n;
	while (test_n--) {
		cin >> N >> M;
		init_set();
		while (M--) {
			int a, b;
			cin >> a >> b;
			join_set(a-1, b-1);
		}
		cout << get_max(size, size+N) << endl;
	}

	return 0;
}

