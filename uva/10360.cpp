
#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;

#define SIZE 1025
#define SIZE_SQR SIZE*SIZE

int pop[ SIZE ][ SIZE ];
int sum[ SIZE ][ SIZE ];

/* O(n^2) */
void calc_sum() {
	int i, j;
	sum[0][0] = pop[0][0];

	for (i = 1; i < SIZE; ++i) {
		sum[i][0] = sum[i-1][0] + pop[i][0];
		sum[0][i] = sum[0][i-1] + pop[0][i];
	}

	for (i = 1; i < SIZE; ++i)
	for (j = 1; j < SIZE; ++j)
		sum[i][j] = pop[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}

int get_sum(int x1, int y1, int x2, int y2) {
	return sum[x2][y2]
		- ( x1 > 0 ? sum[x1-1][y2] : 0 )
		- ( y1 > 0 ? sum[x2][y1-1] : 0 )
		+ ( x1 > 0 && y1 > 0 ? sum[x1-1][y1-1] : 0 );
}

int main() {
	int tt, d, n,
		x, y, killn,
		o_x, o_y, max_killn;

	cin >> tt;
	while (tt--) {
		cin >> d
			>> n;

		memset(pop, 0, sizeof(int)*SIZE_SQR);

		/*
		for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			assert(pop[i][j] == 0);
		*/

		while (n--) {
			cin >> x >> y;
			cin >> pop[x][y];
		}

		calc_sum();

		max_killn = -1;

		for (int i = d; i+d < SIZE; ++i)
		for (int j = d; j+d < SIZE; ++j) {
			killn = get_sum(i-d, j-d, i+d, j+d);

			if (killn > max_killn) {
				max_killn = killn;
				o_x = i;
				o_y = j;
			}
		}

		cout << o_x << ' ' << o_y << ' ' << max_killn << endl;
	}

	return 0;
}

