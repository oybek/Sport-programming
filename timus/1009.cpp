
#include <iostream>
using namespace std;

long n, k;

long count(long n, long k, bool zero_prev) {
	if (n == 1) {
		if (zero_prev)
			return (k-1);
		else
			return k;
	}
	else {
		if (zero_prev)
			return count(n-1, k)*count(n-1, k-1);
		else
			return count(n-1, k-1)*count(n-1, k);
	}
}

int main() {
	cin >> n >> k;
	cout << (k-1)*count(n-1, k, false) << endl;

	return 0;
}

