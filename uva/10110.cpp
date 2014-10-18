
#include <cmath>
#include <iostream>

int main() {
	using namespace std;

	long long n, m;
	while (cin >> n) {
		if (n == 0) break;
		m = floor(sqrt(n));
		if (m*m == n) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}

