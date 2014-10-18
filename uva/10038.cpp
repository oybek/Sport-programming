
#include <cmath>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;
	int was[3000], n, n1, n2, i, m, d;

	while (cin >> n) {
		m = n-1;
		fill(was, was+n, false);

		cin >> n2;
		for (i = 1; i < n; ++i) {
			n1 = n2;
			cin >> n2;

			d = abs(n2 - n1);
			if ((1 <= d) && (d <= n-1) && !was[ d ]) {
				was[ d ] = true;
				--m;
			}
		}
		if (m == 0) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}

	return 0;
}

