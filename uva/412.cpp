
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define MAX_N 50

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main() {
	int N;
	int a[ MAX_N ];

	cout << fixed << setprecision(6);

	/*bool first = true;*/
	while (cin >> N) {
		if (N == 0)
			break;

		for (int i = 0; i < N; ++i)
			cin >> a[i];

		int d = N*(N-1)/2;
		int n = 0;
		for (int i = 0; i < N; ++i)
			for (int j = i+1; j < N; ++j)
				n += (gcd(a[i], a[j]) == 1);

		/*if (first) first = false;*/
		/*else cout << endl;*/
		if (n == 0) {
			cout << "No estimate for this data set.";
		} else {
			cout << round(sqrt( 6.0*d/n )*1000000)/1000000;
		}
		cout << endl;
	}

	return 0;
}

