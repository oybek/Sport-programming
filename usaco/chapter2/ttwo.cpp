
/*
ID: aybek.h2
PROG: ttwo
LANG: C++
*/

#define PROB_NAME "ttwo"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

enum { UP, DOWN, LEFT, RIGHT };

const int forest_size = 10;
char forest[ forest_size+1 ][ forest_size+1 ];

struct point
{
	int x, y, dir;

	void turnright()
	{
		switch (dir)
		{
			case UP:	dir = RIGHT; break;
			case RIGHT:	dir = DOWN; break;
			case DOWN:	dir = LEFT; break;
			case LEFT:	dir = UP; break;
		}
	}

	void act()
	{
		switch (dir)
		{
			case UP:
				if (x-1 < 0 ||
					forest[x-1][y] == '*') turnright();
				else --x;
				break;

			case DOWN:
				if (x+1 >= forest_size ||
					forest[x+1][y] == '*') turnright();
				else ++x;
				break;

			case LEFT:
				if (y-1 < 0 ||
					forest[x][y-1] == '*') turnright();
				else --y;
				break;

			case RIGHT:
				if (y+1 >= forest_size ||
					forest[x][y+1] == '*') turnright();
				else ++y;
				break;
		}
	}
};

vector<int> cow_minutes[ forest_size ][ forest_size ];

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	point cows, farmer;

	for (int i = 0; i < forest_size; ++i)
		scanf("%s", forest[i]);

	// find coordinates of farmer and cows
	for (int i = 0; i < forest_size; ++i)
		for (int j = 0; j < forest_size; ++j)
			switch (forest[i][j])
			{
				case 'C':
					cows.x = i;
					cows.y = j;
					cows.dir = UP;
					break;

				case 'F':
					farmer.x = i;
					farmer.y = j;
					farmer.dir = UP;
					break;
			}

	const int minute_max = 1000;

	for (int minute = 0; minute < minute_max; ++minute)
	{
		cow_minutes[ cows.x ][ cows.y ].push_back(minute);
		cows.act();
	}
	for (int minute = 0; minute < minute_max; ++minute)
	{
		if
		(
			binary_search
			(
				cow_minutes[farmer.x][farmer.y].begin(),
				cow_minutes[farmer.x][farmer.y].end(),
				minute
			)
		)
		{
			printf("%d\n", minute);
			return 0;
		}
		farmer.act();
	}

	printf("0\n");
	return 0;
}

