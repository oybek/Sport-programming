
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

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	int b, r, y, k, bk, rk, yk;
	string s;

	bk = rk = yk = 0;

	cin >> b >> r >> y
		>> k;

	while (k--) {
		cin >> s;
		if (s == "Yellow") {
			yk = 1;
		} else
		if (s == "Red") {
			rk = 1;
		} else
		if (s == "Blue") {
			bk = 1;
		}
	}

	if (bk+rk+yk == 0) {
		cout << 0 << endl;
	} else {
		cout
			<< (bk? b: 1) * (rk? r: 1) * (yk? y: 1)
			<< endl;
	}

	return 0;
}

