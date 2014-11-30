
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

#define in_range(x, a, b) ((x >= a) && (x <= b))

#define UP_BOUND	6227020800
#define LOW_BOUND	10000

int n;
int main()
{
	while (scanf("%d", &n) != EOF)
	{
		switch (n) {
			case 8:		puts("40320"); break;
			case 9:		puts("362880"); break;
			case 10:	puts("3628800"); break;
			case 11:	puts("39916800"); break;
			case 12:	puts("479001600"); break;
			case 13:	puts("6227020800"); break;

			default:
				if (n < 0)
					puts( !(n&1) ? "Underflow!" : "Overflow!" );
				else
					puts( (n < 8) ? "Underflow!" : "Overflow!" );
		}
	}

	return 0;
}

