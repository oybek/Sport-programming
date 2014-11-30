
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

typedef long long int64;

#define SIZE 50000
int64 a[ SIZE+1 ], s[ SIZE+1 ];

int main()
{
	int t;

	a[0] = s[0] = 0;
	for (int64 i = 1; i <= SIZE; ++i)
	{
		a[i] = i*i*i;
		s[i] = s[i-1] + a[i];
	}

	while (scanf("%d", &t) != EOF)
	{
		printf("%lld\n", s[t]);
	}

	return 0;
}

