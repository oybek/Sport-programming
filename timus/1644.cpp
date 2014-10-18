
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

	int32_t expNum, n, maxHungry = 2, minSatisf = 10;

	cin >> expNum;
	repeat(expNum) {
		string s;
		int32_t n;

		cin >> n >> s;

		switch (s[0]) {
			case 'h': if (n > maxHungry) maxHungry = n; break;
			case 's': if (n < minSatisf) minSatisf = n; break;
		}
	}

	if (minSatisf > maxHungry) cout << minSatisf;
	else cout << "Inconsistent";
	cout << endl;

	return 0;
}

