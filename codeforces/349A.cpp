
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
	int n, t, c25 = 0, c50 = 0;
	cin >> n;
	for (; n--; ) {
		cin >> t;
		switch (t) {
			case 25:
				++c25;
				break;

			case 50:
				if (c25 > 0) {
					--c25;
					++c50;
				} else {
					cout << "NO";
					return 0;
				}
				break;

			case 100:
				if (c25 > 0 && c50 > 0) {
					--c25, --c50;
				} else
				if (c25 > 2) {
					c25 -= 3;
				} else {
					cout << "NO";
					return 0;
				}
				break;
		}
	}
	cout << "YES";

	return 0;
}

