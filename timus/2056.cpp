
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

int c[6];

int main() {
	int n, S = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		S += t;
		++c[t];
	}

	if (c[3] > 0) {
		cout << "None\n";
	} else
	if (c[5] == n) {
		cout << "Named\n";
	} else
	if (10*S >= 45*n) {
		cout << "High\n";
	} else {
		cout << "Common\n";
	}

	return 0;
}

