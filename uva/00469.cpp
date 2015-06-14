
#include <bitset>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define SIZE 128

int n, m, c;
char a[ SIZE ][ SIZE ];
bitset<SIZE> sign[ SIZE ];

int floodfill(int x, int y) {
	if (x < 0 ||
		y < 0 ||
		x >= n ||
		y >= m ||
		sign[x][y] ||
		a[x][y] != 'W') return 0;

	sign[x][y] = 1;
	return 1
		+ floodfill(x-1, y)
		+ floodfill(x+1, y)
		+ floodfill(x, y-1)
		+ floodfill(x, y+1)
		+ floodfill(x-1, y-1)
		+ floodfill(x-1, y+1)
		+ floodfill(x+1, y-1)
		+ floodfill(x+1, y+1);
}

void reset_sign() {
	for (int i = 0; i < SIZE; ++i)
		sign[i].reset();
}

int main() {
	int tt, x, y;
	bool first = true;

	scanf("%d", &tt);

	while (getchar() != '\n');
	while (getchar() != '\n');

	while (tt--) {
		char s[ SIZE ];

		m = 0;
		for (n = 0; ; ++n) {
			fgets(s, SIZE, stdin);
			if (isdigit(s[0]))
				break;

			if (m == 0)
				m = strlen(s);
			strcpy(a[n], s);
		}

		if (first) first = false;
		else puts("");

		while (1) {
			reset_sign();

			sscanf(s, "%d%d", &x, &y);

			printf("%d\n", floodfill(--x, --y));

			if ((fgets(s, SIZE, stdin) == NULL) || (s[0] == '\n')) {
				break;
			}
		}
	}

	return 0;
}

