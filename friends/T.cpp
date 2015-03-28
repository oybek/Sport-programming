
#include <cmath>
#include <bitset>
#include <iostream>
using namespace std;

bool is_prime(int n) {
	if (n <= 1) return 0;
	if (n == 2) return 1;
	if (n%2==0) return 0;
	for (int d = 3; d*d <= n; d += 2)
		if (n%d==0)
			return 0;
	return 1;
}

int main() {
	int c;
	cin >> c;
	for (int a = 0; a <= c; ++a) {
		int a3 = a*a*a;
		for (int b = a+1; b <= c; ++b) {
			int b3 = b*b*b;
			if ((b3-a3)%2 == 0 && is_prime((b3-a3)/2)) {
				cout << a << ' ' << b << endl;
			}
		}
	}

	return 0;
}

