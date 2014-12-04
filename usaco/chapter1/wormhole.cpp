
/*
ID: aybek.h2
PROG: wormhole
LANG: C++
*/

#define PROB_NAME "wormhole"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 12

int N;
int X[ N_MAX+1 ], Y[ N_MAX+1 ];
int partner[ N_MAX+1 ];
int next_on_right[ N_MAX+1 ];

bool loop_exist()
{
	for (int start = 1; start <= N; ++start)
	{
		int pos = start;
		for (int count = 0; count < N; ++count)
			pos = next_on_right[partner[pos]];
		if (pos != 0) return true;
	}
	return false;
}

int solve()
{
	int i;
	for (i = 1; i <= N; ++i)
		if (partner[i] == 0)
			break;

	if (i > N) // process solution
		return loop_exist();

	int ans = 0;

	for (int j = i+1; j <= N; ++j)
		if (partner[j] == 0)
		{
			partner[i] = j;
			partner[j] = i;

			ans += solve();

			partner[i] = partner[j] = 0;
		}

	return ans;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d%d", X+i, Y+i);

	for (int i=1; i <= N; ++i) // set next_on_right[i]...
		for (int j=1; j <= N; ++j)
			if (X[j] > X[i] && Y[i] == Y[j])
				if (next_on_right[i] == 0 ||
						X[j]-X[i] < X[next_on_right[i]]-X[i])
					next_on_right[i] = j;

	printf("%d\n", solve());

	return 0;
}

