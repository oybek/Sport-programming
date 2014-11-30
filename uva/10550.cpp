
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
	while (1)
	{
		int pos, a, b, c;
		scanf("%d%d%d%d", &pos, &a, &b, &c);
		if (pos + a + b + c == 0)
			break;

		int cwise = 720/9, ccwise = 360/9;

		cwise += 40-abs(pos-a);
		ccwise += abs(a-b);
		cwise += 40-abs(b-c);

		printf("%d\n", (cwise+ccwise)*9);
	}

	return 0;
}

