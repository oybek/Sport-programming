
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

const int n_max = 20;

bool is_good(int * a, int * b, int i, int n)
{
}

int main()
{
	int n,
		a[ n_max+1 ]
		b[ n_max+1 ];

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
		scanf("%d", a+i);

	while (!feof(stdin))
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", b+i);

		for (int i = 0; i < (1<<n); ++i)
		{
		}
	}

	return 0;
}

