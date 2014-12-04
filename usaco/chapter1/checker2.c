
/*
ID: aybek.h2
PROG: checker
LANG: C
*/

#include <stdio.h>
#include <string.h>

int size;
int sol_num;
int a[ 13 ];

struct _board {
 unsigned int a[ 13 ];
} board[ 14 ];

FILE * fin, * fout;
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

  if (!(board[ind].a[ ind ] & (1<<a[ind]))) {
   memcpy(board[ind+1].a, &board[ind].a , 13*sizeof(int));

   for (i = ind, j = a[ind]; i<size && j<size; ++i, ++j)
		 board[ind+1].a[i] |= (1<<j);

	 for (i = ind, j = a[ind]; i<size && j>=0; ++i, --j)
		 board[ind+1].a[i] |= (1<<j);

	 board[ind+1].a[ind] = 65535;
	 for (i = ind; i < size; ++i)
		 board[ind+1].a[i] |= 1<<a[ind];

   dfs(ind+1);
  }
 }

}

int main() {

 fin = fopen("checker"".in", "r");
 fout = fopen("checker"".out", "w");

 fscanf(fin, "%d", &size);
 dfs(0);
 fprintf(fout, "%d\n", sol_num);

 return 0;
}

