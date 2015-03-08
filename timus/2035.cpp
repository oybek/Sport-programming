
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

typedef unsigned long long int64;
int64 x, y, c;

int main() {
	cin >> x >> y >> c;

	bool f = false;
	if (x > y) {
		swap(x, y);
		f = true;
	}

	if (x+y < c) {
		cout << "Impossible\n";
	} else
	if (x+y >= c) {
		if (x >= c) {
			if (f) {
				cout << c << ' ' << 0 << endl;
			} else {
				cout << 0 << ' ' << c << endl;
			}
		} else {
			if (f) {
				cout << c-x << ' ' << x << endl;
			} else {
				cout << x << ' ' << c-x << endl;
			}
		}
	}

	return 0;
}

