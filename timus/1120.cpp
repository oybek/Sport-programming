#include <cstdlib>
#include <iostream>
using namespace std;

#define MAX_P 44721

int main() {
	int N;
	cin >> N;

	for (int p = MAX_P; p > 0; --p) {
		int t1 = p*(p-1);
		if (2*N <= t1)
			continue;

		int t2 = 2*N - t1;
		if (t2%(2*p))
			continue;

		int a = t2/2/p;
		int s2 = p*p + 2*a*p - p;

		if (2*N == s2) {
			cout << a << ' ' << p << endl;
			break;
		}
	}

	return 0;
}

