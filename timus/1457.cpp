
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

	int size;
	double sum = 0.0, n;

	cin >> size;
	repeat(size) {
		cin >> n;
		sum += n;
	}
	printf("%.6f\n", sum/size);

	return 0;
}

