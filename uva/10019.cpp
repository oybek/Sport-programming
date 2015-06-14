
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

void remove_trailing_blanks(char * s) {
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

int count_bit(int b) {
	int c = 0;
	while (b > 0) {
		c += b&1;
		b >>= 1;
	}
	return c;
}

int main() {
	int test_n,
		b1,
		b2;
	char s[ 64 ];

	scanf("%d", &test_n);
	while (test_n--) {
		scanf("%s", s);
		sscanf(s, "%d", &b1);
		sscanf(s, "%x", &b2);

		printf("%d %d\n", count_bit(b1), count_bit(b2));
	}

	return 0;
}

