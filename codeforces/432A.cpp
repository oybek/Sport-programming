
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

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

const int n_max = 2001;
int n, k, y[n_max];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> y[i];
	sort(y, y+n);
	int ans = 0;
	for (int i = 0; i+2 < n; i += 3)
		ans += (k+max(y[i], max(y[i+1], y[i+2])) <= 5);
	cout << ans;

	return 0;
}

