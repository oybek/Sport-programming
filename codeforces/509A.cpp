
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

int a[11][11];

int main() {
	for (int i = 1; i < 11; ++i)
		a[i][1] = a[1][i] = 1;
	for (int i = 2; i < 11; ++i)
		for (int j = 2; j < 11; ++j)
			a[i][j] = a[i-1][j] + a[i][j-1];
	int n;
	cin >> n;
	cout << a[n][n];

	return 0;
}

