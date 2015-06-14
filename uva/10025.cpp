
#include <cmath>
#include <vector>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> k;
		k = abs(k);
		n = floor( (sqrt(8.0*k + 1) - 1) / 2 );
		while ( n*(n+1) < 2*k )
			++n;
		cout << n << endl;
	}

	return 0;
}

