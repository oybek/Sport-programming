
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
#define all(a) a.begin(), a.end()

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

int main() {
	const int n_max = 101;
	int n, t, p, a[n_max];
	fill(a, a+n_max, 0);

	cin >> n;
	cin >> p; while (p--) { cin >> t; a[t] = 1; };
	cin >> p; while (p--) { cin >> t; a[t] = 1; };
	cout << (accumulate(a+1, a+n+1, 0) == n ? "I become the guy." : "Oh, my keyboard!");

	return 0;
}

