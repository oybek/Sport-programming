#include <stdio.h>
int N, t, count[ 25000+1 ];
int main() {
	scanf("%d", &N);
	for (; N--; ++count[ t ]) scanf("%d", &t);
	for (t = 25000; t >= 1; --t) while (count[t]--) printf("%d\n", t);
return 0; }
