
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int * boom = new int [n];
	for (int i = 0; i < n; ++i)
		cin >> boom[i];

	int droid = 0, notused = 0;
	for (int i = 0; i < n; ++i)
		if ((k-boom[i]) > 0)
			droid += k-boom[i];
		else
			notused += boom[i]-k;

	cout << notused << ' ' << droid << endl;


	return 0;
}

