
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
	int tt, t, n, minv, maxv;

	scanf("%d", &tt);
	while (tt--)
	{
		scanf("%d", &n);

		minv = INF;
		maxv = -INF;
		for_(int, i, 0, n)
		{
			scanf("%d", &t);
			minv = min(t, minv);
			maxv = max(t, maxv);
		}

		cout << (maxv-minv)*2 << endl;
	}

	return 0;
}

