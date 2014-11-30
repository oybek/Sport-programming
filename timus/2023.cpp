
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
	int n, ans = 0, pos = 0;
	const int s_max_sz = 256;
	char s[ s_max_sz ];

	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		switch (tolower(s[0]))
		{
			case 'a':
			case 'p':
			case 'o':
			case 'r':
				ans += abs(pos - 0);
				pos = 0;
				break;

			case 'b':
			case 'm':
			case 's':
				ans += abs(pos - 1);
				pos = 1;
				break;

			case 'd':
			case 'g':
			case 'j':
			case 'k':
			case 't':
			case 'w':
				ans += abs(pos - 2);
				pos = 2;
				break;
		}
	}
	printf("%d", ans);

	return 0;
}

