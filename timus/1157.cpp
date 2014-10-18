
/*
http://acm.timus.ru/problem.aspx?space=1&num=1157
*/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
	int m, n, k, lsqr, divn, divm, d, l;

	cin >> m >> n >> k;

	for (l = 1; l <= 10000; ++l) {
		lsqr = round(sqrt(l));

		divn = 0; divm = 0;

		for (d = 1; d <= lsqr; ++d) {
			//cout << l << " % " << d << " = " << l%d << endl;
			
			if ((l % d) == 0)
				++divn;

			//cout << l-k << " % " << d << " = " << l%d << endl;
			
			if (((l-k) > 0) && (((l-k) % d) == 0))
				++divm;
		}

		if ((divn == n) && (divm == m)) {
			cout << l << endl;
			return 0;
		}
	}
	cout << 0 << endl;

	return 0;
}

