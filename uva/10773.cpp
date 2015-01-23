
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1

int main()
{
	int test_n, d, v, u;

	cout << fixed << setprecision(3);

	cin >> test_n;

	for (int test_i = 1; test_i <= test_n; ++test_i)
	{
		cin >> d >> v >> u;

		cout	<< "Case " << test_i << ": ";
		if (u <= v || !u || !v) {
			cout << "can't determine\n";
		} else {
			cout << d / sqrt(u*u - v*v) - static_cast<double>(d) / u << endl;
		}
	}

	return 0;
}

