
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

#define MIN_N 1
#define MAX_N 10000

#define MIN_R 0
#define MAX_R 1000000000

bitset<MAX_N> was;
int a[ MAX_N ];

int v_sz;
int v[ MAX_N ];

int main()
{
	int n, r;
	was.reset();

	scanf("%d%d", &n, &r);
	for_(int, i, 0, n)
		scanf("%d", a+i);

	for (int i = 0; i < n; ++i)
	{
		int wasn = 0;
		v_sz = 0;
		v[ v_sz++ ] = lower_bound(a, a+n, a[i]+r+1);

		if (was[ v[ v_sz-1] ])
			++wasn;
		else
			was[ v[ v_sz-1 ] ] = 1;
	}

	return 0;
}

