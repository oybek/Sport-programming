
#include <iostream>
using namespace std;

int dig[ 10 ];

#define dig_init() \
	dig[0] = dig[1] = dig[2] = dig[3] = dig[4] = \
	dig[5] = dig[6] = dig[7] = dig[8] = dig[9] = 0

void dig_count(int n) {
	for ( ; n > 0; n /= 10 )
		++dig[ n % 10 ];
}

void dig_show() {
	cout << dig[0];
	for ( int i = 1; i < 10; ++i )
		cout << ' ' << dig[i];
}

int main() {
	int N, n;
	cin >> N;
	while ( N-- ) {
		dig_init();

		cin >> n;
		for ( ; n > 0; --n )
			dig_count(n);
		dig_show();
		cout << endl;
	}

	return 0;
}

