
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
#include <numeric>
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

int main() {
	const int n_max = 30001;
	int n, t, a[n_max];

	cin >> n >> t;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= t && i <= n; i += a[i])
		if (i == t) {
			cout << "YES";
			return 0;
		}
	cout << "NO";

	return 0;
}

