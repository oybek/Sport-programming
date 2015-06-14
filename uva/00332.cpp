
#include <string>
#include <iostream>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); ++i)

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a; a = b%a; b = c;
	}
	return b;
}

int gen(int d, int n) {
	int m = 0;
	while (n--) {
		m *= 10;
		m += d;
	}
	return m;
}

int main() {
	int n;
	string s;

	for (int testi = 1; ; ++testi) {
		cin >> n;
		if (n == -1) break;

		/* 0.a(b)*/
		cin >> s;
		int a = 0, b = 0;

		REP(i, 2, s.size()-n-1) {
			a *= 10;
			a += (s[i]-'0');
		}
		REP(i, s.size()-n, s.size()-1) {
			b *= 10;
			b += (s[i]-'0');
		}

		int den = gen(9, n);

		a *= den;

		for (int i = s.size()-n-2; i > 0; --i) {
			den *= 10;
		}

		int c = gcd(a+b, den);
		cout << "Case " << testi << ": " << (a+b)/c << '/' << den/c << endl;
	}

	return 0;
}

/*
2 0.318
1 0.3
2 0.09
6 0.714285
-1
*/

