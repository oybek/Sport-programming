
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

#define n_max 51
int n;
bitset<n_max> a[n_max];

int fill(int x, int y) {
	if (a[x][y] == 1) return 0;

	for (int i = 1; i <= n; ++i)
		a[x][i] = a[i][y] = 1;

	return 1;
}

int main() {
	int x, y, ans = 0;
	cin >> n;
	for (int i = 1; i <= n*n; ++i) {
		cin >> x >> y;
		if (fill(x, y))
			cout << i << ' ';
	}

	return 0;
}

