
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

int64 product(const vector<int> & a, int i, int j) {
	int64 p = 1;
	for (; i <= j; ++i)
		p *= a[i];
	return p;
}

int main() {
	vector<int> a;

	a.reserve(128);

	int t;
	while (cin >> t) {
		a.resize(0);

		while (t != -999999) {
			a.push_back(t);
			cin >> t;
		}

		int64 max_p = -INF;
		for (int i = 0; i < int(a.size()); ++i)
			for (int j = i; j < int(a.size()); ++j)
				max_p = max(product(a, i, j), max_p);

		cout << max_p << endl;
	}

	return 0;
}

