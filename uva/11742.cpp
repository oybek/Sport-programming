
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

#define n_MAX 9
#define m_MAX 21

int n, m, conf[n_MAX];
struct constraint {
	int a, b, c;
} constraints[m_MAX];

int dist(int v1, int v2) {
	int i, j;
	for (i = 0; i < n && conf[i] != v1; ++i);
	for (j = 0; j < n && conf[j] != v2; ++j);
	return abs(i-j);
}

bool is_good() {
	for (int i = 0; i < m; ++i) {
		if (constraints[i].c > 0) {
			if (dist(constraints[i].a, constraints[i].b) > abs(constraints[i].c)) {
				return false;
			}
		} else
		if (constraints[i].c < 0) {
			if (dist(constraints[i].a, constraints[i].b) < abs(constraints[i].c)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	while (true) {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}

		for (int i = 0; i < m; ++i)
			cin	>> constraints[i].a
				>> constraints[i].b
				>> constraints[i].c;

		int count = 0;

		for (int i = 0; i < n; ++i)
			conf[i] = i;

		do {
			count += is_good();
		} while (next_permutation(conf, conf+n));

		cout << count << endl;
	}

	return 0;
}

