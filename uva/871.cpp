
#include <set>
#include <map>
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

#define SIZE 32

int rown, coln;
char a[SIZE][SIZE];

int dfs_count(int x, int y)
{
	if (x < 0 ||
		y < 0 ||
		x >= rown ||
		y >= coln ||
		a[x][y] == '0')
		return 0;

	a[x][y] = '0';
	return 1
		+ dfs_count(x-1, y-1)
		+ dfs_count(x-1, y)
		+ dfs_count(x-1, y+1)
		+ dfs_count(x,   y-1)
		+ dfs_count(x,   y+1)
		+ dfs_count(x+1, y-1)
		+ dfs_count(x+1, y)
		+ dfs_count(x+1, y+1);
}

int str_len(char * s) {
	int l = 0;
	while (	(*s == '0') ||
			(*s == '1') )
	{
		++s;
		++l;
	}
	return l;
}

int main()
{
	int tt;
	cin >> tt;

	bool first = true;

	while (getchar() != '\n');
	while (getchar() != '\n');

	while (tt--)
	{
		coln = 0;
		rown = -1;
		for_(int, i, 0, INF)
		{
			if (!fgets(a[i], SIZE, stdin))
				break;

			if (str_len(a[i]) == 0)
				break;

			if (rown == -1)
				rown = str_len(a[i]);

			++coln;
		}

		int max_size = 0;
		for_(int, i, 0, rown)
		for_(int, j, 0, coln)
			if (a[i][j] == '1')
				max_size = max(dfs_count(i, j), max_size);

		if (first) first = false;
		else cout << endl;
		cout << max_size << endl;
	}

	return 0;
}

