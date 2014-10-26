
#include <cmath>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a; a = b%a; b = c;
	}
	return b;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << abs(gcd(a, b)) << endl;

	return 0;
}

