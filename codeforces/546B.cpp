
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define n_max 100000

int n, cnt[n_max];

int main() {
	cin >> n;
	int t, ans = 0;
	while (n--) {
		cin >> t;
		++cnt[t];
	}
	for (int i = 1; i < n_max; ++i) {
		if (cnt[i] > 1) {
			cnt[i+1] += cnt[i]-1;
			ans += cnt[i]-1;
		}
	}
	cout << ans;

	return 0;
}

