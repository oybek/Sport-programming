
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
	int n, m, s = 0, c = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		if (i%m == 0)
			++n;
		++c;
	}
	cout << c;

	return 0;
}

