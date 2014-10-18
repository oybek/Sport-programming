
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;
	int n; cin >> n;
	double s = 0.0;
	while (n--) {
		double t;
		cin >> t;

		s += t;
	}
	cout.precision(19);
	cout << s << endl;

	return 0;
}

