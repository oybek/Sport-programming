
#include <math.h>
#include <stdio.h>

int min_cp(int n) {
	int flag = 0, cp = 0;
	while ( n > 1 ) {
		++cp;
		if ( !flag ) flag = n & 1;
		n >>= 1;
	}
	return cp + flag;
}

int main() {
	int n, i = 0;
	while ( 1 ) {
		scanf("%d", &n);
		if ( n < 0 )
			break;
		printf("Case %d: %d\n", ++i, min_cp(n));
	}

	return 0;
}

