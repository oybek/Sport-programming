
/*
ID: aybek.h2
PROG: checker
LANG: C
*/

// TODO
// program works 1.54 seconds
// need less then 1.0 second
#define PROB_NAME "checker"

#include <stdio.h>

FILE * fin, * fout;

#define uint unsigned int

#define MAX_SIZE 13

char size;
int sol_num;
char a[ MAX_SIZE ];

struct _board {
	char a[ MAX_SIZE ];
};

void dfs(register int i, register uint row) {
	register int j, d;

	if (i >= size) {
		if (sol_num < 3) {
			fprintf(fout, "%d", a[0]+1);
			for (j = 1; j < i; ++j)
				fprintf(fout, " %d", a[j]+1);
			fprintf(fout, "\n");
		}
		++sol_num;

		return;
	}

	for (a[i] = 0; a[i] < size; ++a[i]) {

		// if row is not attacked
		if (!(row & 1<<a[i])) {
			// check diagonally attacks
			for (j = 0; j < i; ++j) {
				d = a[i]-a[j];
				if (d < 0) d = -d;

				if (i-j == d)
					break;
			}
			if (i == j) {
				dfs(i+1, row|(1<<a[i]));
			}
		}
	}
}

int main() {
	fin = fopen(PROB_NAME".in", "r");
	fout = fopen(PROB_NAME".out", "w");

	fscanf(fin, "%d", &size);
	dfs(0, 0u);
	fprintf(fout, "%d\n", sol_num);

	return 0;
}

