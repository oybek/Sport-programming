
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

const int n_max = 300001;
int n, a[n_max];
uint64 s[n_max];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a+n, greater<int>());

	s[0] = a[0];
	for (int i = 1; i < n; ++i)
		s[i] = s[i-1]+a[i];

	uint64 s = 0;
	for (int i = 0; i < n; ++i) {
		s += ::s[i];
		if (i+1 < n)
			s += a[i+1];
	}
	cout << s;

	return 0;
}

