
#include <cstdio>
#include <bitset>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

#define SIZE 101

/*bitset<SIZE> was[ SIZE ];*/

int rown, coln;
char a[ SIZE ][ SIZE ];

int dfs_count(int x, int y) {
	if (x < 0 ||
		y < 0 ||
		x >= rown ||
		y >= coln ||
		/*was[x][y] ||*/
		a[x][y] == '.')
		return 0;

	/*was[x][y] = 1;*/
	a[x][y] = '.';
	return 1
		+ dfs_count(x-1, y-1)
		+ dfs_count(x-1, y)
		+ dfs_count(x-1, y+1)
		+ dfs_count(x, y-1)
		+ dfs_count(x, y+1)
		+ dfs_count(x+1, y-1)
		+ dfs_count(x+1, y)
		+ dfs_count(x+1, y+1);
}

int main() {
	while (scanf("%d%d", &rown, &coln) != EOF) {
		if (!rown && !coln)
			break;

		for (int i = 0; i < rown; ++i)
			scanf("%s", a[i]);

		int star_n = 0;
		for (int i = 0; i < rown; ++i)
			for (int j = 0; j < coln; ++j)
				if (dfs_count(i, j) == 1)
					++star_n;

		printf("%d\n", star_n);
	}

	return 0;
}

