
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

	const size_t size = 6;
	size_t tickPrise;
	size_t bnote[ size ] = { 10, 50, 100, 500, 1000, 5000 };
	size_t money[ size ] = {};

	repeat( size )
		cin >> money[i_];
	cin >> tickPrise;

	if (money[0]) {
		size_t tickNum = 0;
		for (size_t i = 0; i < size; ++i) {
			tickNum += money[i]*bnote[i]/tickPrise;
		}

		cout << tickNum << endl;
	} else {
	}

	return 0;
}

