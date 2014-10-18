
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define fib_size 45

int T, N, dst_size;
int fib[ fib_size + 1 ];
int num[ fib_size + 1 ];
string src, dst;

void init_fib() {
	fib[ 1 ] = 1;
	fib[ 2 ] = 2;
	for ( int i = 3; i <= fib_size; ++i )
		fib[ i ] = fib[ i-2 ] + fib[ i-1 ];
}

int fibn(int n) {
	for ( int i = 1; i <= fib_size; ++i )
		if ( fib[i] == n )
			return i;
	return 0;
}

int main() {
	init_fib();

	cin >> T;
	while ( T-- ) {
		cin >> N;

		dst_size = 0;
		for ( int i = 1; i <= N; ++i ) {
			cin >> num[i];
			dst_size = max(dst_size, fibn(num[i]));
		}

		getline(cin, src);
		getline(cin, src);

		dst.resize(dst_size);
		fill(dst.begin(), dst.end(), ' ');

		int si, ni;
		for ( si = 0, ni = 1; ni <= N; ++ni, ++si ) {
			while ( !((src[ si ] >= 'A') && (src[ si ] <= 'Z')) )
				++si;

			dst[ fibn(num[ni])-1 ] = src[ si ];
		}

		cout << dst << endl;
	}

	return 0;
}

