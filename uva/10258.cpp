
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
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

#define MAX_CN 100
#define MAX_PN 9

bitset<MAX_CN+1> was;
int WAn[ MAX_CN+1 ][ MAX_PN+1 ];
int AC [ MAX_CN+1 ];

struct contestant_t {
	int n, p, t;

	friend
	bool operator < (const contestant_t & a1, const contestant_t & a2)
	{
		if (a1.p != a2.p)
			return a1.p > a2.p;
		else if (a1.t != a2.t)
			return a1.t < a2.t;
		else
			return a1.n < a2.n;
	}
} contestant[ MAX_CN+1 ];

void reset_all()
{
	was.reset();
	for (int i = 0; i <= MAX_CN; ++i)
	for (int j = 0; j <= MAX_PN; ++j)
		WAn[i][j] = 0;

	for (int i = 0; i <= MAX_CN; ++i)
	{
		AC[i] = 0;
		contestant[i].n = i;
		contestant[i].t = 0;
		contestant[i].p = 0;
	}
}

int main()
{
	bool first = true;
	int tt, cn, pn, tm;

	const int s_max_sz = 64;

	char s[ s_max_sz ],
		 verdict;

	scanf("%d", &tt);
	while (getchar() != '\n');
	while (getchar() != '\n');

	while (tt--)
	{
		reset_all();
		while (1)
		{
			if ((fgets(s, s_max_sz, stdin) == NULL) || (s[0] == '\n'))
				break;

			sscanf(s, "%d%d%d %c", &cn, &pn, &tm, &verdict);

			was[cn] = 1;
			if ((AC[ cn ]&(1<<pn)) == 0)
			{
				switch (toupper(verdict))
				{
					case 'I':
						++WAn[ cn ][ pn ];
						break;

					case 'C':
						AC[ cn ] |= (1<<pn);
						contestant[ cn ].p += 1;
						contestant[ cn ].t += WAn[ cn ][ pn ] * 20 + tm;
						break;
				}
			}
		}

		sort(contestant, contestant+MAX_CN+1);

		if (first) first = false;
		else puts("");
		for (int i = 0; i <= MAX_CN; ++i)
		{
			if (was[contestant[i].n] > 0)
			{
				printf("%d %d %d\n",
						contestant[i].n,
						contestant[i].p,
						contestant[i].t);
			}
		}
	}

	return 0;
}

