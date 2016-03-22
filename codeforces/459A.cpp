
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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	if (x1 == x2 && y1 != y2) {
		cout	<< x1+abs(y2-y1) << ' ' << y1 << ' '
				<< x1+abs(y2-y1) << ' ' << y2;
	} else
	if (y1 == y2 && x1 != x2) {
		cout	<< x1 << ' ' << y1+abs(x1-x2) << ' '
				<< x2 << ' ' << y1+abs(x1-x2);
	} else
	if (abs(x1-x2) == abs(y1-y2) && y1 != y2) {
		cout	<< x1 << ' ' << y2 << ' '
				<< x2 << ' ' << y1;
	} else {
		cout << -1;
	}

	return 0;
}

