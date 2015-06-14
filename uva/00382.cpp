
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool was[ 60000 ];

void factorize(int n, vector<int> & factors) {
	int i, c, lim;

	if ( n == 0 ) return;

	for ( c = n; c%2 == 0; c /= 2 )
		factors.push_back(2);

	lim = static_cast<int>(sqrt(c))+1;
	for ( i = 3; i <= lim; ) {
		if ( c % i == 0 ) {
			factors.push_back(i);
			c /= i;
			lim = static_cast<int>( sqrt(c) )+1;
		} else { i += 2; }
	}

	if (c > 1 && c != n) factors.push_back(c);
}

int sum( const vector<int> & v ) {
	unsigned int ind = 0, i, n;
	int s = 1;

	for ( ind = 1; ind+1u < 1u<<v.size(); ++ind ) {
		n = 1;
		for ( i = 0; i < v.size(); ++i )
				n *= (ind&(1<<i) ? v[i]: 1);

		if ( !was[n] ) {
			s += n;
			was[n] = true;
		}
	}
	return s;
}

int main() {
	int n, s;
	vector<int> factors;
	factors.reserve(256);

	printf("PERFECTION OUTPUT\n");
	for ( ;; ) {
		fill(was, was+60000, false);
		factors.resize(0);

		scanf("%d", &n);
		if ( !n )
			break;

		if ( n == 1 ) {
			printf("%5d  DEFICIENT\n", n);
			continue;
		}

		factorize(n, factors);
		s = sum( factors );

		printf("%5d  ", n);
		if ( s > n ) {
			printf("ABUNDANT\n");
		} else
		if ( s < n ) {
			printf("DEFICIENT\n");
		} else {
			printf("PERFECT\n");
		}
	}
	printf("END OF OUTPUT\n");

	return 0;
}

