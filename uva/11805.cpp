
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int i, t, n, k, p, a;
	cin >> t;
	for ( i = 1; t--; ++i )
	{
		cin >> n >> k >> p;
		cout << "Case " << i << ": " << (!(a = (k+p)%n) ? n: a ) << endl;
	}

	return 0;
}

