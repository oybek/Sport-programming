
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

uint64 kuti = 10000000,
	   lakh = 100000,
	   hajar = 1000,
	   shata = 100;

void write(uint64 n) {
	if (kuti <= n) {
		if (n / kuti >= 100) {
			write(n / kuti);
		} else {
			cout << ' ' << n / kuti;
		}
		cout << " kuti";
		n %= kuti;
	}
	if (lakh <= n) {
		if (n / lakh >= 100) {
			write(n / lakh);
		} else {
			cout << ' ' << n / lakh;
		}
		cout << " lakh";
		n %= lakh;
	}
	if (hajar <= n) {
		if (n / hajar >= 100) {
			write(n / hajar);
		} else {
			cout << ' ' << n / hajar;
		}
		cout << " hajar";
		n %= hajar;
	}
	if (shata <= n) {
		cout << ' ' << n / shata << " shata";
		n %= shata;
	}
	if (n > 0) {
		cout << ' ' << n;
	}
}

int main() {
	uint64 n;
	for (int test_i = 1; cin >> n; ++test_i) {
		cout << setw(4) << test_i << '.';

		write(n);
		cout << endl;
	}

	return 0;
}

