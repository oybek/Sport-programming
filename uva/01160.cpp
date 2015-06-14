
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

#define parent_sz_MAX 100001

int parent[parent_sz_MAX];
void init_set() {
	for (int i = 0; i < parent_sz_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void join_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

int main() {
	bool eof;
	int count, x, y;
	while (1) {
		eof = true;
		count = 0;
		init_set();

		while (cin >> x) {
			eof = false;
			if (x == -1) break;
			cin >> y;
			if (find_set(x) == find_set(y)) ++count;
			join_set(x, y);
		}

		if (eof) break;

		cout << count << endl;
	}

	return 0;
}

