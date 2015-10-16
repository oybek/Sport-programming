
#include <iostream>
#include <algorithm>
using namespace std;

int memo[82][11];

int backtrack(int s, int deep) {
	if (memo[s][deep] != -1)
		return memo[s][deep];

	if (deep == 10)
		return s == 0;

	int c = 0, m = min(s, 9);
	for (int i = 0; i <= m; ++i) {
		c += backtrack(s-i, deep+1);
	}

	return memo[s][deep] = c;
}

int main() {
	int S;

	for (int i = 0; i < 82; ++i)
		fill(memo[i], memo[i]+11, -1);

	cin >> S;
	cout << backtrack(S, 1) + (S == 1);

	return 0;
}

