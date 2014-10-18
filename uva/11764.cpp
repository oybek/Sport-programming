
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, vsize, h, l, i, testi;
	vector<int> v; v.reserve(50);

	cin >> N;
	for (testi = 1; testi <= N; ++testi) {
		cin >> vsize;

		h = l = 0;
		v.resize(vsize);
		for (i = 0; i < vsize; ++i)
			cin >> v[i];

		for (i = 1; i < vsize; ++i)
			if (v[i] > v[i-1])
				++h;
			else
			if (v[i] < v[i-1])
				++l;

		cout << "Case " << testi << ": " << h << ' ' << l << endl;
	}

	return 0;
}

