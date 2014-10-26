
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

typedef pair<int, int> ii;

void factorize(int n, vector<ii> & v) {
	int i, c, lim;

#define add(n) \
	if (v.size() == 0 || v.back().first != n) \
		v.push_back(make_pair(n, 1)); \
	else ++v.back().second;

	if (!n) return;

	for (c = n; c%2 == 0; c >>= 1) {
		add(2);
	}

	lim = int(sqrt(c))+1;
	for (i = 3; i <= lim;) {
		if (c%i == 0) {
			add(i);
			lim = int(sqrt(c /= i))+1;
		} else
			i += 2;
	}

	if (c > 1) {
		add(c);
	}
}

int main() {
	int n;
	vector<ii> f; f.reserve(1024);

	while (1) {
		scanf("%d", &n);

		if (!n)
			break;

		f.resize(0);
		factorize(n, f);
		printf("%d : %d\n", n, int(f.size()));
	}

	return 0;
}

