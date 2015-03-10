
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

int test_n;
long double H, L, R, S;

int main() {
	cin >> test_n;
	while (test_n--) {
		cin >> L;
		H = L*3.0/5.0;
		R = L/5.0;

		S = M_PI * R * R;
		cout << fixed << setprecision(2) << S << ' ' << H*L - S << endl;
	}

	return 0;
}

