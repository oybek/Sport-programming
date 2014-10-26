
#include <iostream>
using namespace std;

typedef unsigned long long uint64;

uint64 pow(uint64 a, uint64 n) {
	if (n == 0) {
		return 1ull;
	} else {
		if (n%2 == 0) {
			uint64 t = pow(a, n/2);
			return t*t;
		} else {
			return a*pow(a, n-1);
		}
	}
}

int main() {
	uint64 a, b;
	cin >> a >> b;
	cout << pow(a, b) << endl;

	return 0;
}

