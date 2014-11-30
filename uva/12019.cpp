
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

int day[13][32];

const char * s[] = {
	"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

int main()
{
	int w = 6;
	for (int i = 1; i <= 12; ++i)
	{
		switch (i)
		{
			case 1: case 3:
			case 5: case 7:
			case 8: case 10:
			case 12:
				for (int j = 1; j <= 31; ++j)
				{
					day[i][j] = w;
					if (++w > 7)
						w = 1;
				}
				break;

			case 2:
				for (int j = 1; j <= 28; ++j)
				{
					day[i][j] = w;
					if (++w > 7)
						w = 1;
				}
				break;

			case 4: case 6:
			case 9: case 11:
				for (int j = 1; j <= 30; ++j)
				{
					day[i][j] = w;
					if (++w > 7)
						w = 1;
				}
				break;
		}
	}
	int tt, m, d;
	scanf("%d", &tt);
	while (tt--)
	{
		scanf("%d%d", &m, &d);
		puts(s[ day[m][d] ]);
	}

	return 0;
}

