
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

#define H 30
#define M 6

int main()
{
	int h, m;
	float ans;
	while (1)
	{
		scanf("%d:%d", &h, &m);
		if (!h && !m)
			break;

		h *= H;
		m *= M;

		ans = min(h-m, 360-(h-m));
		printf("%.3f\n", roundf(ans*1000)/1000);
	}

	return 0;
}

