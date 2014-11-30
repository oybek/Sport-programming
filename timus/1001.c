
#include <math.h>
#include <stdio.h>

#define SIZE 140000
typedef long long int64;

int main()
{
	int i = 0;
	int64 v[ SIZE ];
	for (; scanf("%lld", v+i) != EOF; ++i);
	for (; i-- > 0; printf("%.4lf\n", sqrt(v[i])));

	return 0;
}

