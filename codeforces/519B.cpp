
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
	cerr << s << ':';
	for (; a != b; ++a)
		cerr << ' ' << *a;
	cerr << endl;
}

const int n_max = 100001;
int n, a[n_max], b[n_max], c[n_max];

int main() {
	vector<int> diff;

	cin >> n;
	for (int i = 0; i   < n; ++i) cin >> a[i];
	for (int i = 0; i+1 < n; ++i) cin >> b[i];
	for (int i = 0; i+2 < n; ++i) cin >> c[i];

	sort(a, a+n);
	sort(b, b+n-1);
	sort(c, c+n-2);

	set_difference(a, a+n  , b, b+n-1, back_inserter(diff));
	set_difference(b, b+n-1, c, c+n-2, back_inserter(diff));

	for (int t : diff) cout << t << endl;

	return 0;
}

