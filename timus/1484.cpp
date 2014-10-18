
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define repeat(a) for (int i_ = 0; i_ < (a); ++i_)

int main() {
	using namespace std;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	float r, y, n;
	cin >> r >> y >> n;

	if (y == 10.0 && r != y) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (y >= r) {
		cout << 0 << endl;
		return 0;
	}

	int x;
	if (y < r) {
		for (x = 1; round((10.0*r*n+10.0*x)/(n+x))/10.0 > y; ++x);
	}

	cout << x << endl;

	return 0;
}

