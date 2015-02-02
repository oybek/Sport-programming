
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

#define n_MAX 101

int n, d, a;
string A1[n_MAX], A2[n_MAX], A3[n_MAX];

int parent[ n_MAX ];
void init_set() {
	for (int i = 0; i < n_MAX; ++i)
		parent[i] = i;
}
int find_set(int x) {
	return x == parent[x] ? x : parent[x] = find_set(parent[x]);
}
void union_set(int x, int y) {
	parent[find_set(x)] = parent[find_set(y)];
}

int main() {
	init_set();

	cin	>> n
		>> d >> a;
	for (int i = 0; i < n; ++i) {
		cin >> A1[i];
		A2[i].resize(n, '0');
		A3[i].resize(n, '0');
	}

	/* add edges not creating cycle */
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (A1[i][j] == '1') {
				if (find_set(i) != find_set(j)) {
					union_set(i, j);
					A2[i][j] = A2[j][i] = '1';
				}
			}
		}
	}

	/* add edges to make graph connected */
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (find_set(i) != find_set(j)) {
				union_set(i, j);
				A2[i][j] = A2[j][i] = '1';
			}
		}
	}

	/* count difference */
	long long cost = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (A1[i][j] != A2[i][j]) {
				switch (A2[i][j]) {
					case '0':
						cost += d;
						A3[i][j] = A3[j][i] = 'd';
						break;
					case '1':
						cost += a;
						A3[i][j] = A3[j][i] = 'a';
						break;
				}
			}
		}
	}

	/* output */
	cout << cost << endl;
	for (int i = 0; i < n; ++i) {
		cout << A3[i] << endl;
	}

	return 0;
}

