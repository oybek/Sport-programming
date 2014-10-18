
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

struct num_t {
	int factor[ 8 ];
	num_t() { clear(); }
	inline
	void clear() {
		factor[ 2 ] = 0;
		factor[ 3 ] = 0;
		factor[ 5 ] = 0;
		factor[ 7 ] = 0;
	}

	inline
	void operator *= (register int n) {
		switch (n) {
			case 9: ++factor[3]; case 3: ++factor[3]; break;
			case 8: ++factor[2]; case 4: ++factor[2]; case 2: ++factor[2]; break;
			case 7: ++factor[7]; break;
			case 6: ++factor[2]; ++factor[3]; break;
			case 5: ++factor[5]; break;
			default: break;
		}
	}

	inline
	friend bool operator == (const num_t & a1, const num_t & a2) {
		if (a1.factor[ 2 ] != a2.factor[ 2 ]) return false;
		if (a1.factor[ 3 ] != a2.factor[ 3 ]) return false;
		if (a1.factor[ 5 ] != a2.factor[ 5 ]) return false;
		if (a1.factor[ 7 ] != a2.factor[ 7 ]) return false;
		return true;
	}
};

int main() {
	int N, M, t;
	register num_t a, b;

	while (1) {
		cin >> N >> M;
		if ( !N && !M )
			break;

		a.clear();
		b.clear();

		for ( ; N--; )
			for ( cin >> t; t > 1; --t )
				a *= t;

		for ( ; M--; )
			for ( cin >> t; t > 1; --t )
				b *= t;

		cout << (a == b ? "YES": "NO") << endl;
	}

	return 0;
}

