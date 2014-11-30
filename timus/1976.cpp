
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

#define MAX_N 1000

int n, m;
int a[ MAX_N+1 ][ MAX_N+1 ];

#define BASE -1

void dfs(int x, int y, int dx, int dy)
{
	if (x < 0 ||
		y < 0 ||
		x >= n ||
		y >= m ||
		a[x][y] == BASE ||
		a[x][y] <= dx*dx + dy*dy)
		return;

	a[x][y] = dx*dx + dy*dy;

	dfs(x-1, y, dx+1, dy);
	dfs(x+1, y, dx+1, dy);
	dfs(x, y-1, dx, dy+1);
	dfs(x, y+1, dx, dy+1);
}

int main()
{
	const int s_sz = 1002;
	char s[ s_sz ];

	scanf("%d%d", &n, &m);
	while (getchar() != '\n');

	for (int i = 0; i < n; ++i)
	{
		fgets(s, s_sz, stdin);
		for (int j = 0; s[j] == '0' || s[j] == '1'; ++j)
			a[i][j] = (s[j] == '0' ? INF: BASE);
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] == BASE)
			{
				a[i][j] = 0;
				dfs(i-1, j, 1, 0);
				dfs(i+1, j, 1, 0);
				dfs(i, j-1, 0, 1);
				dfs(i, j+1, 0, 1);
			}

	for (int i = 0; i < n; ++i)
	{
		bool first = true;
		for (int j = 0; j < m; ++j)
		{
			if (first) first = false;
			else putchar(' ');
			printf("%d", a[i][j]);
		}
		puts("");
	}

	return 0;
}

