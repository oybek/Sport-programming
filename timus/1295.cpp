
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

uint64 mod_pow(uint64 num, uint64 pow, uint64 mod) {
	uint64 res;
	uint64 n = num;
	for(res = 1; pow; pow >>= 1) {
		if (pow & 1)
			res = ((res % mod) * (n % mod)) % mod;
		n = ((n % mod) * (n % mod)) % mod;
	}

	return res;
}

int main() {
	int e = 9;
	int n;
	int num = 1000000000;

	cin >> n;
	while ((
		mod_pow(1, n, num) +
		mod_pow(2, n, num) + 
		mod_pow(3, n, num) +
		mod_pow(4, n, num))%num != 0) {
		num /= 10;
		--e;
	}
	cout << e << endl;

	return 0;
}

