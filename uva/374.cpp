
#include <iostream>
using namespace std;

int pow_mod(int a, int p, int m) {
	if (p == 0) {
		return 1;
	} else
	if (p%2 == 0) {
		int t = pow_mod(a, p/2, m)%m;
		t *= t;
		t %= m;
		return t;
	} else {
		int t = pow_mod(a, p-1, m)%m;
		t *= a%m;
		t %= m;
		return t;
	}
}

int main() {
	int b, p, m;
	while (cin >> b >> p >> m) {
		cout << pow_mod(b, p, m) << endl;
	}

	return 0;
}

