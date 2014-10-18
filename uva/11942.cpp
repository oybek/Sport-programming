
#include <iostream>
using namespace std;

bool ascending(int * a, int size) {
	for ( int i = 1; i < size; ++i )
		if ( a[i] < a[i-1] )
			return false;
	return true;
}

bool descending(int * a, int size) {
	for ( int i = 1; i < size; ++i )
		if ( a[i] > a[i-1] )
			return false;
	return true;
}

int main() {
	const int size = 10;
	int N, a[ size ];

	cin >> N;
	cout << "Lumberjacks:\n";
	while ( N-- ) {
		for ( int i = 0; i < size; ++i )
			cin >> a[ i ];

		if ( ascending(a, size) || descending(a, size) ) {
			cout << "Ordered\n";
		} else {
			cout << "Unordered\n";
		}
	}

	return 0;
}

