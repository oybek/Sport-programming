
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

#define SIZE 3002

int fib[SIZE];

uint64 pow_mod(uint64 a, uint64 n, const uint64 m) {
	if (n == 0) {
		return 1;
	} else
	if (n%2 == 0) {
		uint64 tmp = pow_mod(a, n/2, m);
		return tmp*tmp%m;
	} else {
		return a*pow_mod(a, n-1, m)%m;
	}
}

int main() {
	int test_n, len;
	uint64 a, b, mod;

	cin >> test_n;
	while (test_n--) {
		cin >> a >> b >> mod;

		fib[0] = 0%mod;
		fib[1] = 1%mod;
		for (len = 2; len < SIZE; ) {
			fib[len] = (fib[len-1] + fib[len-2])%mod;
			++len;

			if (fib[len-1] == 1 && fib[len-2] == 0) {
				len -= 2;
				break;
			}
		}

		cout << fib[pow_mod(a%len, b, len)] << endl;
	}

	return 0;
}

