
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

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define MAX_L 50

int a_sz;
int a[ MAX_L ];

int insert(int n)
{
	int i, count = 0;
	for (i = a_sz-1; a[i] > n; --i)
	{
		a[i+1] = a[i];
		++count;
	}
	a[i+1] = n;
	++a_sz;
	return count;
}

int main()
{
	int tt; /* number of test cases */
	scanf("%d", &tt);
	while (tt--)
	{
		int L;
		scanf("%d", &L);

		a_sz = 0;
		int ans = 0, t;
		for (int i = 0; i < L; ++i)
		{
			scanf("%d", &t);

			ans += insert(t);
		}

		printf("Optimal train swapping takes %d swaps.\n", ans);
	}

	return 0;
}

