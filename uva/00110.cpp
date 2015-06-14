
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

inline
int ilog2(int n) {
	int i;
	for ( i = 0; n >= 2; ++i )
		n >>= 1;
	i += (n > 0);
	return i;
}

bool equal(
	const vector<int> & a,
	const vector<int> & b,
	const vector<int> & works
) {
	int i;
	for ( i = 0; i < (int) a.size(); ++i )
		if ( works[i] && (a[i] != b[i]) )
			break;

	return i == (int) a.size();
}

bool two_equal(
	const vector<vector<int> > & v,
	const vector<int> & works
) {
	int i, j;
	for ( i = 0; i < (int) v.size(); ++i )
		for ( j = i+1; j < (int) v.size(); ++j )
			if ( equal(v[i], v[j], works) )
					return true;

	return false;
}

int main() {
	bool found;
	int T, P, N, i, j, n;
	vector<int> works; works.reserve(15);
	vector<vector<int> > v;
	v.resize(100);

	cin >> T;

	while ( T-- ) {
		cin	>> P >> N;

		works.resize(P);
		v.resize( N );
		for ( i = 0; i < N; ++i ) {
			v[i].resize( P );
			for ( j = 0; j < P; ++j )
				cin >> v[i][j];
		}

		for ( n = min(ilog2(N), P); n < N; ++n ) {
			int m = n;
			for ( i = works.size()-1; i >= 0; --i, --m ) {
				works[i] = (m > 0 ? 1: 0);
			}

			found = false;
			do {
				if ( !two_equal(v, works) ) {
					found = true; 
					break;
				}
			} while ( next_permutation(works.begin(), works.end()) );

			if ( found ) {
				cout << n << endl;
				break;
			}
		}
	}

	return 0;
}

