
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define R(a, b) (rand()%(b-a+1)+a)

/* affects to runtime */
#define T 25
#define N 10000
#define M 100000

/* doesn't affect to runtime */
#define A R(0, 10000)
#define X R(1, N)
#define Y R(1, N)
#define C R(0, 10000)

#define PF printf

#define REPEAT(n) for (int i = (n); i--; )

int main()
{
	srand(time(NULL));

	PF("%d\n", T);
	REPEAT(T)
	{
		PF("%d %d %d\n", N, M, A);
		REPEAT(M)
		{
			PF("%d %d %d\n", X, Y, C);
		}
	}

	exit(0);
}

