
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int n, c[5];

int main() {
	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		++c[t];
	}

	int ans = c[4], t;
	ans += (t = min(c[3], c[1]));

	c[3] = max(c[3]-t, 0);
	c[1] = max(c[1]-t, 0);

	ans += c[3];
	ans += c[2]/2;

	c[2] %= 2;

	ans += c[2];
	if (c[2] > 0)
		c[1] = max(c[1]-2, 0);

	ans += c[1]/4 + (c[1]%4 ? 1 : 0);

	cout << ans << endl;

	return 0;
}

