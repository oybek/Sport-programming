#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;

	int maxy = k;
	int maxx = n/k;
	if (n%k)
		++maxx;

	int ** grid = new int* [maxx];
	for (int i = 0; i < maxx; ++i)
		grid[i] = new int [maxy];

	for (int i = 0; i < maxx; ++i)
		for (int j = 0; j < maxy; ++j)
			grid[i][j] = -1;

	int ** ptr = grid;
	int i = 0, j = 0;
	while (n--) {
		cin >> grid[i][j];
		++i;
		if (i == maxx) {
			i = 0;
			++j;
			if (j == maxy)
				break;
		}
	}

	for (int i = 0; i < maxx; ++i) {
		for (int j = 0; j < maxy; ++j)
			if (grid[i][j] != -1) {
				printf("%4d", grid[i][j]);
			}
		printf("\n");
	}

	return 0;
}

