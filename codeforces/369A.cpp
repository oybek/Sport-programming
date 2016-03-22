
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

int main() {
	int n, m, k, t, cnt = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> t;

		if (t == 1) {
			if (m > 0)
				--m;
			else
				++cnt;
		} else {
			if (k > 0)
				--k;
			else
			if (m > 0)
				--m;
			else
				++cnt;
		}
	}
	cout << cnt;

	return 0;
}

