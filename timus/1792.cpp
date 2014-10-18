
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

bool isValid(int * a, int size) {
	if ((a[1] + a[2] + a[3])%2 != a[4])
		return false;
	if ((a[0] + a[2] + a[3])%2 != a[5])
		return false;
	if ((a[0] + a[1] + a[3])%2 != a[6])
		return false;

	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int a[ 7 ];
	for (int i = 0; i < 7; ++i)
		cin >> a[ i ];

	if (!isValid(a, 7))
		for (int i = 0; i < 7; ++i) {
			a[i] = !a[i];
			if (isValid(a, 7)) break;
			a[i] = !a[i];
		}

	for (int i = 0; i < 7; ++i)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}

