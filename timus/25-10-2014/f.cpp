
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<long, long> ll;

void factorize(int n, vector<ll> & v) {
	int i, c, lim;

#define add(x) \
	if (v.size() == 0 || v.back().first != x) \
		v.push_back(make_pair(x, 1)); \
	else ++v.back().second;

	if (!n)
		return;

	for (c = n; c%2 == 0; c >>= 1) {
		add(2);
	}

	lim = long(sqrt(c))+1;
	for (i = 3; i <= lim;) {
		if (c%i == 0) {
			add(i);
			lim = long(sqrt(c /= i))+1;
		} else
			i += 2;
	}

	if (c > 1) {
		add(c);
	}
}

int main() {
	long n;
	cin >> n;
	vector<ll> a;
	factorize(n, a);

	for (int i = 0; i < int(a.size()); ++i) {
		cout << a[i].first << ' ' << a[i].second << endl;
	}

	return 0;
}

