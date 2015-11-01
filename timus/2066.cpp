
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

#define INF 1000000009
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	const int size = 3;
	int a[size], ans = INF;
	cin >> a[0] >> a[1] >> a[2];

	sort(a, a+size);

	do {
		ans = min(ans, a[0] + a[1] + a[2]);
		ans = min(ans, a[0] + a[1] - a[2]);
		ans = min(ans, a[0] + a[1] * a[2]);

		ans = min(ans, a[0] - a[1] + a[2]);
		ans = min(ans, a[0] - a[1] - a[2]);
		ans = min(ans, a[0] - a[1] * a[2]);

		ans = min(ans, a[0] * a[1] + a[2]);
		ans = min(ans, a[0] * a[1] - a[2]);
		ans = min(ans, a[0] * a[1] * a[2]);
	} while (next_permutation(a, a+size));

	cout << ans << endl;

	return 0;
}

