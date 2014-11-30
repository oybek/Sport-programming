
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
	int ans, t, n;
	for_(int, i, 1, INF)
	{
		ans = 0;

		scanf("%d", &n);
		if (!n)
			break;

		while (n--)
		{
			scanf("%d", &t);
			ans = ans + (t ? 1: -1);
		}
		printf("Case %d: %d\n", i, ans);
	}

	return 0;
}

