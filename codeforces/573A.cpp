
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

#define n_max 100001
int n, t, p = -1;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		while (!(t%2)) t/=2;
		while (!(t%3)) t/=3;
		if (p != -1 && p != t) {
			cout << "NO";
			return 0;
		}
		p = t;
	}
	cout << "YES";
	return 0;
}

