
/*
ID: aybek.h2
PROG: nocows
LANG: C++
*/

#define PROB_NAME "nocows"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_UP_BOUND 200
#define K_UP_BOUND 100

int D[ K_UP_BOUND ][ N_UP_BOUND ];

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif
	int N, K;
	scanf("%d%d", &N, &K);

	for(int k=1; k<=K; ++k)
			D[k][0] = D[k][1] = 1;

	for (int k=1; k<=K; ++k)
		for (int n=1; n<=N; n+=2)
			for (int c=1; c<n; c+=2)
				D[k][n] = ( D[k][n] + D[k-1][c]*D[k-1][n-c-1] ) % 9901;

	printf("%d\n", (D[K][N] - D[K-1][N] + 9901) % 9901);

	return 0;
}

