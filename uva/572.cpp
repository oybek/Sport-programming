
#include <cstdio>
#include <iostream>
using namespace std;

int rown, coln;
char a[ 101 ][ 101 ];

void flood_fill(int x, int y) {
	if (x < 1 ||
		y < 1 ||
		x > rown ||
		y > coln ||
		a[x][y] == '*')
		return;
	a[x][y] = '*';

	flood_fill(x-1, y-1);
	flood_fill(x  , y-1);
	flood_fill(x+1, y-1);

	flood_fill(x-1, y);
	flood_fill(x+1, y);

	flood_fill(x-1, y+1);
	flood_fill(x  , y+1);
	flood_fill(x+1, y+1);
}

int main() {
	while (scanf("%d%d", &rown, &coln) != EOF) {
		if (!rown && !coln)
			break;

		for (int i = 1; i <= rown; ++i)
			scanf("%s", &(a[i][1]));

		int ans = 0;
		for (int i = 1; i <= rown; ++i)
			for (int j = 1; j <= coln; ++j)
				if (a[i][j] == '@') {
					++ans;
					flood_fill(i, j);
				}

		printf("%d\n", ans);
	}

	return 0;
}

