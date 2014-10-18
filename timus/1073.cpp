
#include <cmath>
#include <iostream>

char memo[60001] = {};

int f(int n) {
	if (n <= 0)		return 0;
	if (memo[n])	return memo[n];

	int min = f(n-1)+1;
	for (int i = 2; i*i <= n; ++i) {
		min = std::min(min, f(n-i*i)+1);
	}

	return memo[n] = min;
}

int main() {
	using namespace std;
	int n, i;
	cin >> n;
	cout << f(n) << endl;

	return 0;
}

