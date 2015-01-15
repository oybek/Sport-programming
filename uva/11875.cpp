
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

#define N_MAX 10
int N, test_n, a[N_MAX];

int main()
{
	scanf("%d", &test_n);
	for (int test_i = 1; test_i <= test_n; ++test_i)
	{
		scanf("%d", &N);
		assert(N <= N_MAX);
		for (int i = 0; i < N; ++i)
			scanf("%d", a+i);
		printf("Case %d: %d\n", test_i, a[N/2]);
	}

	return 0;
}

