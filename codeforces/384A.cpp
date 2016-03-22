
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

int main() {
	int n;
	bool f = true;

	cin >> n;
	cout << (n%2 ? SQR(n/2) + SQR(n/2+1) : n*n/2) << endl;
	for (int i = 0; i < n; ++i) {
		if (n%2 == 0)
			f = !f;
		for (int j = 0; j < n; ++j) {
			putchar(f ? 'C' : '.');
			f = !f;
		}
		puts("");
	}

	return 0;
}

