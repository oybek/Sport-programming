
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
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

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

const int n_max = 1000;
int n, l, a[n_max];

int main() {
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a+n);

	int max_dist = 0;
	for (int i = 1; i < n; ++i)
		max_dist = max(max_dist, a[i]-a[i-1]);

	cout << fixed << setprecision(9);
	cout << max(max_dist/2.0,
				max((a[0]   != 0 ?       a[0]*1.0 : 0),
					(a[n-1] != l ? (l-a[n-1])*1.0 : 0)));

	return 0;
}

