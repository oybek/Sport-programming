
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_substr(const vector<int> & xs, const vector<int> & ys) {
	unsigned int i, j;
	for (i = j = 0; i < ys.size(); ++i, ++j) {
		if (j >= xs.size())
			return false;
		while (ys[i] != xs[j])
			if (++j >= xs.size())
				return false;
	}
	return true;
}

void convert(int n, int b, vector<int> & nb) {
	nb.resize(0);
	for (; n > 0; n /= b)
		nb.push_back(n%b);
}

int main() {
	int x, y;
	cin >> x >> y;

	/*
	if (x < y) {
		cout << "No solution\n";
	} else if (x == y) {
		cout << "2\n";
	} else {
	*/

	vector<int> xb, yb;
	xb.reserve(100);
	yb.reserve(100);
	for (int base = 2; base <= x; ++base) {
		convert(x, base, xb);
		convert(y, base, yb);

		if (is_substr(xb, yb)) {
			cout << base << endl;
			return 0;
		}
	}
	cout << "No solution\n";

	return 0;
}

