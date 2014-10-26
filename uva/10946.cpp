
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 50

int rown, coln;
char a[ SIZE ][ SIZE ];

int dfs_count(char c, int x, int y) {
	if (x < 0 ||
		y < 0 ||
		x >= rown ||
		y >= coln ||
		/*was[x][y] ||*/
		a[x][y] != c)
		return 0;

	a[x][y] = '.';
	return 1
		+ dfs_count(c, x-1, y)
		+ dfs_count(c, x, y-1)
		+ dfs_count(c, x, y+1)
		+ dfs_count(c, x+1, y);
}

int main() {
	vector<pair<int, char> > ans;
	ans.reserve(1024);

	for (int tt = 1; true; ++tt) {
		scanf("%d%d", &rown, &coln);
		if (!rown && !coln)
			break;

		for (int i = 0; i < rown; ++i)
			scanf("%s", a[i]);

		ans.resize(0);
		for (int i = 0; i < rown; ++i)
			for (int j = 0; j < coln; ++j)
				if (a[i][j] != '.')
					ans.push_back(make_pair(-dfs_count(a[i][j], i, j), a[i][j]));

		sort(ans.begin(), ans.end());

		printf("Problem %d:\n", tt);
		for (int i = 0; i < int(ans.size()); ++i)
			printf("%c %d\n", ans[i].second, -ans[i].first);
	}

	return 0;
}

