
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

typedef unsigned long long uint64;

uint64 gcd(uint64 a, uint64 b)
{
	uint64 c;
	while ( a != 0 ) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

uint64 lcm(uint64 a, uint64 b)
{
	return (a*b)/gcd(a, b);
}

#define MAX_N 1000
int p[ MAX_N ];
bitset<MAX_N> was;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p+i);
		--p[i];
	}

	was.reset();

	vector<int> cyc;
	cyc.reserve(1024);
	for (int i = 0; i < n; ++i) {
		if (was[i]) continue;

		int c = 0;
		do {
			was[i] = 1;
			i = p[i];
			++c;
		} while (!was[i]);

		cyc.push_back(c);
	}

	uint64 ans = cyc[0];
	for (int i = 1; i < int(cyc.size()); ++i)
	{
		ans = lcm(ans, cyc[i]);
	}
	printf("%llu\n", ans);

	return 0;
}

