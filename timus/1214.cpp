
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

void P(long& x, long& y)
{
  int i, j;
  if (x>0 && y>0)
  {
    for (i = 1; i <= x+y; i++)
    {
      y = x*x+y;
      x = x*x+y;
      y = sqrt(x+(y/labs(y))*(-labs(y)));
      for (j = 1; j <= 2*y; j++)
        x = x-y;
    }
  }
}

void P_clone(long & a, long & b) {
	if (a <= 0 || b <= 0) return;

	if (a%2) {
		if (b%2);
		else		std::swap(a, b);
	} else {
		if (b%2)	std::swap(a, b);
		else;
	}
}

int main() {
	using namespace std;

	long a, b;
	cin >> a >> b;
	P_clone(a, b);
	cout << a << ' ' << b << endl;

	/*
	long a, b;
	for (a = -100; a <= 100; ++a)
		for (b = -100; b <= 100; ++b) {
			long a1, a2, b1, b2;
			a1 = a2 = a;
			b1 = b2 = b;

			P(a1, b1);
			P_clone(a2, b2);

			if ((a1 != a2) && (b1 != b2)) {
				cout	<< "f(" << a << ", " << b << ") = "
						<< " {" << a1 << ", " << b1 << "}\n"
						<< " {" << a2 << ", " << b2 << "}\n";
			}
		}
		*/
	/*
	if (a%2) {
		if (b%2)	cout << a << ' ' << b << endl;
		else		cout << b << ' ' << a << endl;
	} else {
		if (b%2)	cout << b << ' ' << a << endl;
		else		cout << a << ' ' << b << endl;
	}

	for (long x = 0; x < 10; ++x)
		for (long y = 0; y < 10; ++y) {
			long a = x, b = y;
			P(a, b);
			cout	<< "f(" << x << ", " << y << ") = "
					<< " {" << a << ", " << b << "}\n";
		}
	*/

	return 0;
}

