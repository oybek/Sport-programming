
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

template <class T>
T gcd(T a, T b) {
	T c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

ll get_prime_factor(ll n) {
	ll lim = pow(n, 1.0/3.0);
	for (int d = 2; d <= lim; ++d)
		if (n%d == 0)
			return d;

	for (int k = 1; k <= lim; ++k) {
		for (int d = 0; d <= static_cast<ll>(pow(n, 1.0/6.0)/(4*sqrt(k)))+1; ++d) {
			ll a = sqrt(4*k*n) + d;
			ll t = a*a - 4*k*n;

			if (t < 0) continue;

			ll b = sqrt(t);
			if (b*b == t) {
				ll dd = gcd(a-b, n);

				if (1 < dd && dd < n)
					return dd;
			}
		}
	}
	return -1;
}

bool is_prime(int n) {
	return get_prime_factor(n) == -1;
}

int main() {
	int n;
	cin >> n;
	if (is_prime(n)) {
		cout << 1 << endl << n;
		return 0;
	}

	int p = n-1;
	while (!is_prime(--p));
	if (is_prime(n-p)) {
		cout << 2 << endl << p << ' ' << n-p;
		return 0;
	}

	for (int i = 2; i < n-p; ++i) {
		if (is_prime(i) && is_prime(n-p-i)) {
			cout
				<< 3 << endl
				<< i << ' ' << p << ' ' << n-p-i;
			break;
		}
	}

	return 0;
}

