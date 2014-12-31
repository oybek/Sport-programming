
/*
ID: aybek.h2
PROG: checker
LANG: C
*/

/*
TODO DONE
program works 0.780 seconds
need less then 0.5 seconds
*/

#define PROB_NAME "checker"

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20
#define MAX_DEEP MAX_SIZE+1

int size;
int sol_num;
int a[ MAX_SIZE ];

struct _board {
	unsigned int a[ MAX_SIZE ];
} board[ MAX_DEEP ];

FILE * fin, * fout;

#define MARK(ind, x, y) \
		for (i = x, j = y; i<size && j<size; ++i, ++j)	\
			board[ind].a[i] |= (1<<j);					\
		for (i = x, j = y; i<size && j>=0; ++i, --j)	\
			board[ind].a[i] |= (1<<j);					\
		board[ind].a[x] = 65535;						\
		for (i = x; i < size; ++i)						\
			board[ind].a[i] |= 1<<y;

#define COPY(src, dst) \
		memcpy(board[dst].a, &board[src].a , MAX_SIZE*sizeof(int))


#define ATTACKED(x, y) (board[x].a[ x ] & (1<<y))


void dfs(register int ind) {
	register int i, j;

	if (ind >= size) {
		if (sol_num < 3) {
			fprintf(fout, "%d", a[0]+1);
			for (j = 1; j < ind; ++j)
				fprintf(fout, " %d", a[j]+1);
			fprintf(fout, "\n");
		}

		++sol_num;
		return;
	}

	for (a[ind] = 0; a[ind] < size; ++a[ind]) {

		if (!ATTACKED(ind, a[ind])) {
			COPY(ind, ind+1);
			MARK(ind+1, ind, a[ind]);
			dfs(ind+1);
		}
	}

}

int main() {

	fin = fopen(PROB_NAME".in", "r");
	fout = fopen(PROB_NAME".out", "w");

	fscanf(fin, "%d", &size);
	dfs(0);
	fprintf(fout, "%d\n", sol_num);

	return 0;
}

