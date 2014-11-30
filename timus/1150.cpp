
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

int sol[] =
{ 488889, 600000, 600000, 600000, 600000, 600000, 600000, 600000, 600000, 600000 };

int main()
{
	int ans[ 10 ];
	memset(ans, 0, sizeof(int)*10);

	int n;
	scanf("%d", &n);

	while (n >= 999999)
	{
		for (int i = 0; i < 10; ++i)
			ans[i] += sol[i];
		n -= 999999;
	}

	while (n > 0)
	{
		for (int t = n; t > 0; t /= 10)
			++ans[t%10];
		--n;
	}

	for (int i = 0; i < 10; ++i)
		printf("%d\n", ans[i]);

	return 0;
}

