
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

	const size_t size = 15001;
	int32_t n, num[ size ] = {};

	cin >> n;
	for (size_t i = 0; i < n; ++i) {
		size_t t;
		cin >> t;
		++num[ t ];
	}

	for (size_t i = 0; i < size; ++i) {
		if (num[ 5-num[i]%5 ]) {
		}
	}

	return 0;
}

