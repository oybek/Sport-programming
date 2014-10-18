
/*
http://acm.timus.ru/problem.aspx?space=1&num=1207
*/

#include <stdio.h>
#include <stdlib.h>

struct coord {
	int x, y, i;
};

int compare(const void * p1, const void * p2)
{
	if (((struct coord *) p1)->x < ((struct coord *) p2)->x)
		return -1;
	else if (((struct coord *) p1)->x > ((struct coord *) p2)->x)
		return 1;
	else if (((struct coord *) p1)->y < ((struct coord *) p2)->y)
		return -1;
	else if (((struct coord *) p1)->y > ((struct coord *) p2)->y)
		return 1;
	else
		return 0;
}

int main() {
	int N, i;
	struct coord * a;

	scanf("%d", &N);
	a = (struct coord *) malloc(sizeof (struct coord) * N);
	for (i = 0; i < N; i++) {
		scanf("%d%d", &a[ i ].x, &a[ i ].y);
		a[ i ].i = i;
	}

	qsort(a, (size_t) N, sizeof (struct coord), compare);

	printf("%d %d\n", a[ N/2 ].i + 1, a[ N/2-1 ].i + 1);


	return 0;
}

