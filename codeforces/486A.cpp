
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
#include <numeric>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
#if 0
	int n, f = 0;
	n = 10;
	for (int i = 1; i <= n; ++i) {
		f += (i%2 ? -1 : 1) * i;
		cout << f << endl;
	}
#endif
	int64 n;
	cin >> n;
	cout << (n%2 ? -(n/2+1) : n/2) << endl;

	return 0;
}

