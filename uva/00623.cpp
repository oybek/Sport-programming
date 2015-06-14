
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_DIG_NUM 2048
#define BASE 10000

class ubigint {
	private:
		unsigned int dign;
		unsigned int dig[ MAX_DIG_NUM ];

	public:
		ubigint() : dign(1) { dig[0] = 0; }

		const ubigint &
		operator *= (int n) {
			char tmp;
			unsigned int i, carry = 0;
			for ( i = 0; i < dign; ++i ) {
				tmp = dig[i] * n + carry;

				dig[i] = tmp % BASE;
				carry = tmp / BASE;
			}
			while ( carry > 0 ) {
				dig[ dign++ ] = carry % BASE;
				carry /= BASE; 
			}
			return *this;
		}

		const ubigint &
		operator = (int n) {
			for ( dign = 0; n > 0; n /= BASE)
				dig[ dign++ ] = n % BASE;
			return *this;
		}

		friend ostream &
		operator << (ostream & s, const ubigint & ob) {
			int i;
			for ( i = ob.dign-1; i > 0; --i )
				printf("%04d", ob.dig[i]);
			printf("%d", ob.dig[0]);
			return s;
		}
};

int main() {
	ubigint m;
	m = 1;
	int n = 6;
	do {
		m *= n;
	} while ( --n > 1 );
	cout << m << endl;
	/*
	while ( cin >> n ) {
		cout << n << "!\n";

		m = 1;
		do {
			m *= n;
			cout << m << endl;
		} while ( --n > 1 );

		cout << m << endl;
	}
	*/

	return 0;
}

