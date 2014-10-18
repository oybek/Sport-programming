#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

#define MAX_BOARDSIZE 16
typedef unsigned long SOLUTIONTYPE;
#define MIN_BOARDSIZE 6
SOLUTIONTYPE g_numsolutions = 0;

void Nqueen(int board_size) {
    int aQueenBitRes[MAX_BOARDSIZE];	 /* results */
    int aQueenBitCol[MAX_BOARDSIZE];	 /* marks used columns */
    int aQueenBitPosDiag[MAX_BOARDSIZE]; /* marks used "positive diagonals" */
    int aQueenBitNegDiag[MAX_BOARDSIZE]; /* marks used "negative diagonals" */
    int aStack[MAX_BOARDSIZE + 2];	 /* a stack instead of recursion */
    int *pnStack;

    int numrows = 0; 		/* numrows redundant - could use stack */
    unsigned int lsb;		/* least significant bit */
    unsigned int bitfield;	/* set bits denote possible queen positions */
    int i;
    int odd = board_size & 1; 	/* 1 if board_size odd */
    int board_m1 = board_size - 1; 	/* board size - 1 */
    int mask = (1 << board_size) - 1; 	/* N bit mask of all 1's */

    aStack[0] = -1; 		/* sentinel signifies end of stack */
    for (i = 0; i < (1 + odd); ++i) {
	bitfield = 0;
	if (0 == i) {
	    int half = board_size>>1; /* divide by two */
	    bitfield = (1 << half) - 1;
	    pnStack = aStack + 1; /* stack pointer */
	    aQueenBitRes[0] = 0;
	    aQueenBitCol[0] = aQueenBitPosDiag[0] = aQueenBitNegDiag[0] = 0;
	} else {
	    bitfield = 1 << (board_size >> 1);
	    numrows = 1; /* prob. already 0 */

	    aQueenBitRes[0] = bitfield;
	    aQueenBitCol[0] = aQueenBitPosDiag[0] = aQueenBitNegDiag[0] = 0;
	    aQueenBitCol[1] = bitfield;

	    aQueenBitNegDiag[1] = (bitfield >> 1);
	    aQueenBitPosDiag[1] = (bitfield << 1);
	    pnStack = aStack + 1; /* stack pointer */
	    *pnStack++ = 0; /* row done -- only 1 element & we've done it */
	    bitfield = (bitfield - 1) >> 1;
			/* bitfield -1 is all 1's to the left of the single 1 */
	}
	for (;;) {
	    lsb = -((signed)bitfield) & bitfield;
		/* this assumes a 2's complement architecture */
	    if (0 == bitfield) {
		bitfield = *--pnStack;	/* get prev. bitfield from stack */
		if (pnStack == aStack)	/* if sentinel hit.... */
		    break;
		--numrows;
		continue;
	    }
	    bitfield &= ~lsb; /* bit off -> don't try it again */
	    aQueenBitRes[numrows] = lsb; /* save the result */
	    if (numrows < board_m1) {	/* more rows to process? */
		int n = numrows++;
		aQueenBitCol[numrows] = aQueenBitCol[n] | lsb;
		aQueenBitNegDiag[numrows] = (aQueenBitNegDiag[n] | lsb) >> 1;
		aQueenBitPosDiag[numrows] = (aQueenBitPosDiag[n] | lsb) << 1;
		*pnStack++ = bitfield;
		bitfield = mask & ~(aQueenBitCol[numrows] |
			aQueenBitNegDiag[numrows] | aQueenBitPosDiag[numrows]);
		continue;
	    } else {
		++g_numsolutions;
		bitfield = *--pnStack;
		--numrows;
		continue;
	   }
	}
    }
    g_numsolutions *= 2;
}

int main(int argc, char** argv) {
    ifstream f("checker.in");
    ofstream g("checker.out");
    long boardsize,s[20],ok,k,i,sol=0;
    f>>boardsize;
    Nqueen (boardsize);
    k=1;
    s[k]=0;
    while (k>0) {
	ok=0;
	while(s[k]<boardsize && !ok) {
	    ok=1;
	    s[k]++;
	    for(i=1;i<k;i++)
		if(s[i]==s[k] || abs(s[k]-s[i])==abs(k-i))
		    ok=0;
	}
	if(sol!=3)
	    if(!ok)
		k--;
	    else
		if(k==boardsize) {
		    for(i=1;i<boardsize;i++) {
			for(int j=1;j<=boardsize;j++)
			    if(s[i]==j) g<<j<<" ";
		    }
		    for(i=1;i<=boardsize;i++)
			if(s[boardsize]==i) g<<i;
		    g<<"\n";
		    sol++;
		} else {
		    k++;
		    s[k]=0;
		} else break;
    }
    g<<g_numsolutions<<"\n";
    f.close();
    g.close();
    return 0;
}
