
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

#define loop(n) for (int i = 0; i < n; ++i)
#define GETBIT(n, i) ((n>>i)&1)

int main() {
	long n;
	cin >> n;

	long * st = new long [n];
	loop(n)
	cin >> st[i];

	long lim = 1; lim <<= n;

	long s1, s2;
	long mind = LONG_MAX;

	for (int i = 1; i < lim; ++i) {
		s1 = s2 = 0;
		for (int j = 0; j < n; ++j) {
			if (GETBIT(i, j))
				s1+=st[j];
			else
				s2+=st[j];
		}
		if (abs(s1-s2) < mind)
			mind = abs(s1-s2);
	}
	cout << mind << endl;

	return 0;
}

