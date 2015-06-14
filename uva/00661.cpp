
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

#define n_MAX 21

int main() {
	int n, m, c, i, total_cap, max_total_cap;
	int cap[n_MAX];
	bitset<n_MAX> on;

	for (int test_i = 1; ; ++test_i) {
		/* prepare stage */
		max_total_cap = total_cap = 0;
		on.reset();
		fill(cap, cap+n_MAX, 0);

		/* input stage */
		cin >> n >> m >> c;
		if (!n && !m && !c)
			break;

		cout << "Sequence " << test_i << "\n";

		for (i = 0; i < n; ++i) {
			cin >> cap[i+1];
		}
		for (; m > 0; --m) {
			cin >> i;
			total_cap += (on[i] ? -cap[i] : cap[i]);
			on.flip(i);

			max_total_cap = max(total_cap, max_total_cap);
			if (max_total_cap > c) {
				cout << "Fuse was blown.\n\n";
				for (; m > 1; --m) {
					cin >> i;
				}
				break;
			}
		}
		if (m == 0) {
			cout << "Fuse was not blown.\nMaximal power consumption was " << max_total_cap << " amperes.\n\n";
		}
	}

	return 0;
}

