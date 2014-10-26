
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

#define SIZE 19

typedef long long int64;

int main() {
	int n, tt = 1;
	int64 a[ SIZE ];
	int64 p[ SIZE ];
	int64 max_p;

	while (scanf("%d", &n) != EOF) {
		for (int i = 1; i <= n; ++i)
			scanf("%lld", a+i);

		p[0] = 1;
		for (int i = 1; i <= n; ++i)
			p[i] = p[i-1]*a[i];

		max_p = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = i; j <= n; ++j) {
				int64 p = a[i];
				for (int x = i+1; x <= j; ++x)
					p *= a[x];
				max_p = max(p, max_p);
			}

		printf("Case #%d: The maximum product is %lld.\n\n", tt++, max_p);
	}

	return 0;
}

