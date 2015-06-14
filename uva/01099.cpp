
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

int main()
{
	int n, x, y, t, s = 0;
	for (int i = 1; i < INF; ++i)
	{
		scanf("%d", &n);
		if (!n)
			break;
		scanf("%d%d", &x, &y);
		while (n--)
		{
			scanf("%d", &t);
			s += t;
		}

		printf("Case %d: ", i);
		puts((x*y == s ? "Yes" : "No"));
	}

	return 0;
}

