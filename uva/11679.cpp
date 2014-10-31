
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
	const int max_b = 20;
	int b, n;
	int r[ max_b+1 ];

	while (1)
	{
		scanf("%d%d", &b, &n);
		if (!b && !n)
			break;

		for_(int, i, 0, b)
			scanf("%d", r+i);

		while (n--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);

			r[a-1] -= c;
			r[b-1] += c;
		}

		string ans = "S";
		for_(int, i, 0, b)
			if (r[i] < 0) {
				ans = "N";
				break;
			}

		cout << ans << endl;
	}

	return 0;
}

