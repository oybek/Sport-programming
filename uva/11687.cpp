
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

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

const int s_sz_max = 1000000;
char s[ s_sz_max+1 ];

int get_dign(int n)
{
	int c = 0;
	while (n > 0)
	{
		n /= 10;
		++c;
	}
	return c;
}

int main()
{
	while (1)
	{
		scanf("%s", s);
		if ((s[0] == '1') && !s[1])
		{
			printf("1\n");
			continue;
		}

		if (s[0] == 'E')
			break;

		int x = strlen(s), i;
		for (i = 1; x != 1; ++i)
		{
			x = get_dign(x);
		}
		printf("%d\n", i+1);
	}

	return 0;
}

