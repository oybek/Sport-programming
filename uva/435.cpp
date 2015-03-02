
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

#define a_sz_MAX 21
int a_sz,
	ts,
	a[a_sz_MAX],
	p[a_sz_MAX];

void solve() {
	unsigned int used = 0;
	while (used < (1u<<a_sz)-1) {
		int s = 0;
		for (int i = 0; i < a_sz; ++i)
			if (used&(1<<i))
				s += a[i];
		if (2*s > ts)
			for (int i = 0; i < a_sz; ++i)
				if (used&(1<<i))
					++p[i];
		++used;
	}
}

int main() {
	int test_n;
	bool f = true;

	cin >> test_n;
	while (test_n--) {
		/* prepare stage */
		ts = 0;
		fill(p, p+a_sz_MAX, 0);

		/* input stage */
		cin >> a_sz;
		for (int i = 0; i < a_sz; ++i) {
			cin >> a[i];
			ts += a[i];
		}

		/* solution stage */
		solve();
		if (f) f = false;
		else cout << endl;
		for (int i = 0; i < a_sz; ++i) {
			cout << "party " << i+1 << " has power index " << p[i] << "\n";
		}
	}

	return 0;
}

