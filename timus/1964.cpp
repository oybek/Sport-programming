
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
	int n, k, t, s;
	cin >> n >> k;
	for (s = 0; k--; s += (n-t))
		cin >> t;
	n = max(n-s, 0);
	cout << n << endl;

	return 0;
}

