
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

char s[32];

int main()
{
	for (int i = 1; i < INF; ++i)
	{
		scanf("%s", s);
		switch (*s)
		{
			case 'H':
				printf("Case %d: Hajj-e-Akbar\n", i);
				break;
			case 'U':
				printf("Case %d: Hajj-e-Asghar\n", i);
				break;
			case '*':
				return 0;
		}
	}

	return 0;
}

