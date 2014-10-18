
#include <cmath>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define sqr(a) (a)*(a)

struct coord {
	int x, y;

	friend bool operator < (const coord & a1, const coord & a2) {
		return ( (a1.x == a2.x) ? a1.y < a2.y: a1.x < a2.x );
	}
};

double d(const coord & a, const coord & b) {
	return sqrtf( static_cast<double>(sqr(a.x - b.x) + sqr(a.y - b.y)) );
}

double len(const vector<coord> & v) {
	double s = 0.0;
	size_t i;
	for ( i = 1; i < v.size(); ++i )
		s += d( v[ i-1 ], v[ i ] ) + 16.0;

	return s;
}

int main() {
	size_t i, v_size, testi = 1;
	vector<coord> v; v.reserve(8);

	double l, min_l = 10000000000.0;
	vector<coord> min_v;

	while ( cin >> v_size ) {
		if ( !v_size )
			break;

		v.resize( v_size );

		for ( i = 0; i < v.size(); ++i )
			cin >> v[ i ].x >> v[ i ].y;

		sort(v.begin(), v.end());

		do {
			l = len(v);

			if ( l < min_l ) {
				min_l = l;
				min_v = v;
			}
		} while ( next_permutation(v.begin(), v.end()) );

		cout	<< "**********************************************************\n"
				<< "Network #" << testi << endl;

		for ( i = 1; i < v.size(); ++i ) {
			cout	<< "Cable requirement to connect "
					<< "(" << v[ i-1 ].x	<< "," << v[ i-1 ].y	<< ") to "
					<< "(" << v[ i ].x		<< "," << v[ i ].y		<< ")"
					<< " is " << fixed << setprecision(2) << d(v[ i-1 ], v[i]) + 16.0 << " feet.\n";
		}

		cout << "Number of feet of cable required is " << min_l << ".\n";

		++testi;
	}

	return 0;
}

