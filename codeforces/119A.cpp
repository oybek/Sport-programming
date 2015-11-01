
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

#define gcd __gcd

int main() {
	int a, b, n, f = 1;
	cin >> a >> b >> n;
	while (1) {
		if (n < gcd(a, n)) {
			cout << f;
			break;
		}
		n -= gcd(a, n);
		swap(a, b);
		f = !f;
	}

	return 0;
}

