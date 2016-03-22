
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
	int n, x, y, z, dx, dy, dz;

	x = y = z = 0;
	for (cin >> n; n--; ) {
		cin >> dx >> dy >> dz;
		x += dx;
		y += dy;
		z += dz;
	}

	cout << (!x && !y && !z ? "YES" : "NO");

	return 0;
}

