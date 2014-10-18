
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, i, n, h;
	bool first = true;
	string s; s.reserve(16);

	cin >> N;
	while ( N-- ) {

		if (first) first = false;
		else cout << endl;

		cin >> n >> h;

		s.resize(n);
		for (i = s.size()-1; i >= 0; --i, --h)
			s[i] = char((h > 0) + '0');

		do
			cout << s << endl;
		while (next_permutation(s.begin(), s.end()));
	}

	return 0;
}

