
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

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

void remove_leading_int(char * s)
{
	bool in_number = false;
	while (*s != '\0')
	{
		if (in_number)
		{
			if (isdigit(*s)) *s = ' ';
			else return;
		}
		else
		{
			if (isdigit(*s))
			{
				in_number = true;
				*s = ' ';
			}
		}
		++s;
	}
}

#define N_MAX 101
#define S_LEN_MAX 512

int n;
int a[ N_MAX ][ N_MAX ];
char s[S_LEN_MAX];
bitset<N_MAX+1> was;

int dfs_clear(int x, int y, const char c)
{
	if ((x < 0) ||
		(x >=n) ||
		(y < 0) ||
		(y >=n) ||
		(a[x][y] != c))
		return 0;

	int count = 1;

	a[x][y] = 0;

	count += dfs_clear(x-1, y, c);
	count += dfs_clear(x+1, y, c);
	count += dfs_clear(x, y-1, c);
	count += dfs_clear(x, y+1, c);

	return count;
}

bool all_zero()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != 0)
				return false;
	return true;
}

void show_a()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%3d", a[i][j]);
		puts("");
	}
}

int main()
{
	while (1)
	{
start:
		scanf("%d", &n);
		if (n == 0)
			break;
		while (getchar() != '\n');

		for (int i = 0; i < n; ++i)
			fill(a[i], a[i]+n, n);
		for (int i = 1; i < n; ++i)
		{
			int x, y, m = n;
			fgets(s, S_LEN_MAX, stdin);

			while (sscanf(s, "%d%d", &x, &y) == 2)
			{
				if (m-- < 0)
				{
					puts("wrong");
					goto start;
				}

				a[x-1][y-1] = i;

				remove_leading_int(s);
				remove_leading_int(s);
			}
		}

		was.reset();

		for (int x = 0; x < n; ++x)
			for (int y = 0; y < n; ++y)
			{
				if (a[x][y] == 0)
					continue;

				if (was[ a[x][y] ])
				{
					puts("wrong");
					goto start;
				}
				else
				{
					was[ a[x][y] ] = 1;
					if (dfs_clear(x, y, a[x][y]) != n)
					{
						puts("wrong");
						goto start;
					}
				}
			}

		puts( all_zero() ? "good" : "wrong" );
	}

	return 0;
}

