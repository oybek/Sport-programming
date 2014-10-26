
#include <stdio.h>

#define SIZE 15000

int size, i, m, q, ans = 0;
int a[ SIZE ];

int main() {
	scanf("%d", &size);
	for (i = 0; i < size; ++i)
		scanf("%d", a+i);

	scanf("%d", &m);

	register int x, y, c;

	while (m--) {
		scanf("%d", &q);

		x = 0;
		y = size-1;

		while (x <= y) {
			c = (x+y)>>1;

			if (a[c] < q) {
				x = c+1;
			} else
			if (a[c] > q) {
				y = c-1;
			} else {
				++ans;
				break;
			}
		}
	}

	printf("%d", ans);

	return 0;
}

