
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

int main() {
	int a1, a2, a3, b1, b2, b3, n;
	cin >> a1 >> a2 >> a3
		>> b1 >> b2 >> b3
		>> n;

	int s1 = a1+a2+a3,
		s2 = b1+b2+b3;

	cout << (DIVC(s1, 5) + DIVC(s2, 10) <= n ? "YES" : "NO");

	return 0;
}

