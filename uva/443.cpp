
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 5842
int a_sz;
int a[ SIZE ];
int f[ 4 ] = { 2, 3, 5, 7 };

typedef long long int64;

#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)

#define MAX_HUMBLE 2000000000ll

void backtrack(int64 n, int p)
{
	if (n > MAX_HUMBLE)
		return;

	a[ a_sz++ ] = n;

	for (int i = p; i < 4; ++i)
		backtrack(n*f[i], i);
}

#define GET_PREFIX(i) (\
		(i/10)%10 == 1 || (i%10 == 0) \
			? "th" \
			: s[ min(i%10-1, 3) ])

int main()
{
	backtrack(1, 0);
	sort(a, a+a_sz);

	const char * s[] = { "st", "nd", "rd", "th" };

	int i;
	while (1)
	{
		scanf("%d", &i);
		if (!i)
			break;

		printf("The %d%s humble number is %d.\n", i, GET_PREFIX(i), a[i-1]);
	}

	return 0;
}

