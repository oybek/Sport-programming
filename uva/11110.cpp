
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

void get_ints(const char * s, vector<int> & v)
{
	v.resize(0);
	int t;
	while (sscanf(s, "%d", &t) != EOF)
	{
		v.push_back(t);
		while (*s && !isdigit(*s)) ++s;
		while (isdigit(*s)) ++s;
	}
}

#define MAX_N 100
int n;
int a[ MAX_N ][ MAX_N ];

void flood_fill(int x, int y, int k)
{
	if (x < 0	||
		x >= n	||
		y < 0	||
		y >= n	||
		a[x][y] != k)
		return;

	a[x][y] = -1;

	flood_fill(x-1, y, k);
	flood_fill(x+1, y, k);
	flood_fill(x, y-1, k);
	flood_fill(x, y+1, k);
}

int main()
{
	const int s_max_sz = 256;
	char s[ s_max_sz ];
	vector<int> v; v.reserve(256);

	bitset<MAX_N> was;

	while (1)
	{
		scanf("%d", &n);
		if (!n)
			break;

		while (getchar() != '\n');

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				a[i][j] = 0;

		for (int i = 1; i < n; ++i)
		{
			fgets(s, s_max_sz, stdin);
			get_ints(s, v);
			for (int j = 1; j < int(v.size()); j += 2)
				a[ v[j-1]-1 ][ v[j]-1 ] = i;
		}

		bool ans = true;

		was.reset();
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] == -1)
				continue;

			if (was[ a[i][j] ])
			{
				ans = false;
				break;
			}
			else
			{
				was[ a[i][j] ] = 1;
				flood_fill(i, j, a[i][j]);
			}
		}

		puts( ans ? "good" : "wrong" );
	}

	return 0;
}

