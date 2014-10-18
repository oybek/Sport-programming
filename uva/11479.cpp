
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define is_triangle(a, b, c) ((a < b + c) && (b < a + c) && (c < a + b))

int main() {
	long long n, i, a, b, c;
	cin >> n;
	for ( i = 1; i <= n; ++i ) {
		cin >> a >> b >> c;

		cout << "Case " << i << ": ";
		if ( a > 0 && b > 0 && c > 0 && is_triangle(a, b, c) ) {
			if ( (a == b) && (b == c) )
				cout << "Equilateral";
			else
			if ( (a == b) || (b == c) || (a == c) )
				cout << "Isosceles";
			else
				cout << "Scalene";
		} else {
			cout << "Invalid";
		}
		cout << endl;
	}

	return 0;
}

