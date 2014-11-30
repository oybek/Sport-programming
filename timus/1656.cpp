
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

#define repeat(n) for (int _i = (n); _i--; )

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define sqr(x) (x)*(x)

const int max_n = 9;
int n, a[ max_n ][ max_n ];

void nearest(int cx, int cy, int & ax, int & ay)
{
	int min_d = INF, d;
	for (int x = 0; x < n; ++x)
	for (int y = 0; y < n; ++y)
	{
		if (a[x][y] != 0)
			continue;

		d = sqr(cx - x) + sqr(cy - y);
		if (d < min_d)
		{
			min_d = d;
			ax = x;
			ay = y;
		}
	}
}

int main()
{
	priority_queue<int> pq;

	int t;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = 0;

	repeat(n*n)
	{
		scanf("%d", &t);
		pq.push(t);
	}

	int x, y;
	while (! pq.empty() )
	{
		nearest(n>>1, n>>1, x, y);
		a[x][y] = pq.top();
		pq.pop();
	}

	for (int i = 0; i < n; ++i)
	{
		bool first = true;
		for (int j = 0; j < n; ++j)
		{
			if (first) first = false;
			else putchar(' ');

			printf("%d", a[i][j]);
		}
		puts("");
	}

	return 0;
}

