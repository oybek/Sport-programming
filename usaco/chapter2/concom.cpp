
/*
ID: aybek.h2
PROG: concom
LANG: C++
*/

#define PROB_NAME "concom"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 101

int owns[ SIZE ][ SIZE ];
bool ctrl[ SIZE ][ SIZE ];

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	int n;
	scanf("%d", &n);
	while (n--)
	{
		int i, j, p;
		scanf("%d%d%d\n", &i, &j, &p);
		owns[i][j] = p;
	}

	bool f = true;
	while (f)
	{
		f = false;

		for (int i=1; i < SIZE; ++i)
			for (int j=1; j < SIZE; ++j)
			{
				if (!ctrl[i][j])
				{
					int s = 0;
					for (int k = 1; k < SIZE; ++k)
						s += ctrl[i][k] * owns[k][j];

					if (i == j || s > 50)
					{
						ctrl[i][j] = 1;
						f = true;
					}
				}
			}
	}

	for (int i=1; i < SIZE; ++i)
		for (int j=1; j < SIZE; ++j)
			if (i != j && ctrl[i][j])
				printf("%d %d\n", i, j);

	return 0;
}

