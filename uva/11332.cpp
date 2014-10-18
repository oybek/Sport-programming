
#include <iostream>
using namespace std;

int dig_sum(int n) {
	int s;
	for ( s = 0; n > 0; n /= 10 )
		s += n % 10;
	return s;
}

int main() {
	int n;
	for ( ;; ) {
		cin >> n;

		if ( !n )
			break;

		while ( n >= 10 )
			n = dig_sum(n);

		cout << n << endl;
	}

	return 0;
}

