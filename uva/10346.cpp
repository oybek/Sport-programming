
#include <iostream>
using namespace std;

int main() {
	unsigned long long n, k, s;
	while ( cin >> n >> k ) {
		for ( s = n; n >= k; ) {
			s += n/k;
			n = (n / k) + (n % k);
		}

		cout << s << endl;
	}

	return 0;
}

