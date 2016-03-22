
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
	int n, m;
	bool f = false;

	cin >> n >> m;
	string s1(m, '#'), s2(m-1, '.');
	for (int i = 1; i <= n; ++i)
		if (i%2) {
			cout << s1 << endl;
		} else {
			cout << (f ? "#" : "") << s2 << (f ? "" : "#") << endl;
			f = !f;
		}

	return 0;
}

