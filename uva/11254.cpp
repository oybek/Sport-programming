
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;

	while (1) {
		cin >> n;
		if (n == -1)
			break;

		int a = n, d = 1, max_d = 1;
		while (1) {
			int x = 2*n + d - d*d;
			int y = 2*d;

			if (x < 0)
				break;

			if (x > 0 &&
				x%y == 0) {
				a = x/y;
				max_d = max(max_d, d);
			}

			++d;
		}

		cout << n << " = " << a << " + ... + " << a + max_d-1 << endl;
	}

	return 0;
}

