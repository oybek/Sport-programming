
/*
ID: aybek.h2
PROG: maze1
LANG: C++
*/

#define PROB_NAME "maze1"

#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define W_MAX 38
#define H_MAX 100

int W, H;
int maze[ 2*H_MAX+1 ][ 2*W_MAX+1 ];

void maze_show()
{
	for (int i = 0; i < 2*H+1; ++i)
	{
		for (int j = 0; j < 2*W+1; ++j)
			switch (maze[i][j])
			{
				case 0:
					putchar(' ');
					break;

				case -1:
					putchar('#');
					break;
			}
		putchar('\n');
	}
}

void find_exits(vector<pair<int, int> > & exit)
{
	/*maze_show();*/

	for (int x = 1; x < 2*W+1; x += 2)
	{
		if (maze[0][x] == 0)
		{
			exit.push_back(make_pair(1, x));
		}
		if (maze[ 2*H ][x] == 0)
		{
			exit.push_back(make_pair(2*H-1, x));
		}
	}

	for (int y = 1; y < 2*H+1; y += 2)
	{
		if (maze[y][0] == 0)
		{
			exit.push_back(make_pair(y, 1));
		}
		if (maze[y][2*W] == 0)
		{
			exit.push_back(make_pair(y, 2*W-1));
		}
	}

	assert(exit.size() == 2);
}

int solve()
{
	// find exits
	vector<pair<int, int> > exit;
	find_exits(exit);

	queue<pair<int, int> > Q;

	for (int i = 0; i < int(exit.size()); ++i)
	{
		maze[exit[i].first][exit[i].second] = 1;
		Q.push(exit[i]);
		while ( ! Q.empty() )
		{
			pair<int, int> t = Q.front(); Q.pop();

			if (t.first-2 >= 0 && maze[t.first-1][t.second] == 0)
			if (maze[t.first-2][t.second] == 0 ||
				maze[t.first-2][t.second] - maze[t.first][t.second] > 1)
			{
				maze[t.first-2][t.second] = maze[t.first][t.second]+1;
				Q.push(make_pair(t.first-2, t.second));
			}

			if (t.first+2 < 2*H+1 && maze[t.first+1][t.second] == 0)
			if (maze[t.first+2][t.second] == 0 ||
				maze[t.first+2][t.second] - maze[t.first][t.second] > 1)
			{
				maze[t.first+2][t.second] = maze[t.first][t.second]+1;
				Q.push(make_pair(t.first+2, t.second));
			}

			if (t.second-2 >= 0 && maze[t.first][t.second-1] == 0)
			if (maze[t.first][t.second-2] == 0 ||
				maze[t.first][t.second-2] - maze[t.first][t.second] > 1)
			{
				maze[t.first][t.second-2] = maze[t.first][t.second]+1;
				Q.push(make_pair(t.first, t.second-2));
			}

			if (t.second+2 < 2*W+1 && maze[t.first][t.second+1] == 0)
			if (maze[t.first][t.second+2] == 0 ||
				maze[t.first][t.second+2] - maze[t.first][t.second] > 1)
			{
				maze[t.first][t.second+2] = maze[t.first][t.second]+1;
				Q.push(make_pair(t.first, t.second+2));
			}
		}
	}

	int ans = -1;
	for (int i = 1; i < 2*H+1; i += 2)
		for (int j = 1; j < 2*W+1; j += 2)
			ans = max(maze[i][j], ans);

	return ans;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif
	scanf("%d%d", &W, &H);

	// removing endl
	while (getchar() != '\n');

	for (int i = 0; i < 2*H+1; ++i)
	{
		int c;
		int j = 0;
		while ((c = getchar()) != '\n' && c != EOF)
		{
			maze[i][j] = (c == ' ') ? 0: -1;
			++j;
		}
	}

	printf("%d\n", solve());

	return 0;
}

