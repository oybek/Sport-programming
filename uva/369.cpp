
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * n!/(m!*(n-m)!)
 */
long C(long n, long m) {
	long b = min(m, n-m);
	long c = 1, j = 2;
	for ( long i = max(m, n-m)+1; i <= n; ++i ) {
		c *= i;

		if ( (j <= b) && !(c%j) ) {
			c /= j++;
		}
	}

	return c;
}

int main() {
	long n, m;
	while ( cin >> n >> m ) {
		if ( !n && !m )
			break;
		cout	<< n << " things taken "
				<< m << " at a time is "
				<< C(n, m) << " exactly.\n";
	}

	return 0;
}

