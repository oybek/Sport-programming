
#include <cmath>
#include <iostream>
using namespace std;

#define INFTY 1001

int main()
{	int n, x, x1, x2;
	cin >> n >> x;

	x1 = -INFTY;
	x2 = +INFTY;

	while (n--)
	{	int t;
		cin >> t;

		if (t < 0 && x1 < t) x1 = t;
		else
		if (t > 0 && x2 > t) x2 = t;
	}

	if ((x > x1) && (x < x2))
	{
		if (x > 0)
			cout << x << ' ' << 2*abs(x1)+x << endl;
		else
			cout << 2*abs(x2)+abs(x) << ' ' << abs(x) << endl;
	}
	else
		cout << "Impossible\n";

	return 0;
}

