
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

inline
int one_bitn(int n) {
	int m;
	for ( m = 0; n; n >>= 1 )
		m += n&1;
	return m;
}

string bit_mode(int n) {
	string m;

	if ( !n )
		m.push_back('0');

	for ( ; n; n >>= 1 )
		m.push_back((n&1) + '0');

	reverse(m.begin(), m.end());
	return m;
}

int main() {
	int n;
	for ( ;; ) {
		cin >> n;
		if ( !n )
			break;

		cout	<< "The parity of " << bit_mode(n)
				<< " is " << one_bitn(n) << " (mod 2).\n";
	}

	return 0;
}

