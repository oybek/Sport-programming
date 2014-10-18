#include <stdio.h>
int main() {
	long long int N, M, t;
	register long long int a[8], b[8];
	while (1) {
		scanf("%lld%lld", &N, &M);
		if ( !N && !M ) break;
		a[ 2 ] = a[ 3 ] = a[ 5 ] = a[ 7 ] = 0;
		b[ 2 ] = b[ 3 ] = b[ 5 ] = b[ 7 ] = 0;
		while ( N-- ) {
			scanf("%lld", &t);
			for ( ; t > 1; --t )
				switch (t) {
					case 9: ++a[3]; case 3: ++a[3]; break;
					case 8: ++a[2]; case 4: ++a[2]; case 2: ++a[2]; break;
					case 7: ++a[7]; break;
					case 6: ++a[2]; ++a[3]; break;
					case 5: ++a[5]; break;
					default: break;
				}
		}
		while ( M-- ) {
			scanf("%lld", &t);
			for ( ; t > 1; --t )
				switch (t) {
					case 9: ++b[3]; case 3: ++b[3]; break;
					case 8: ++b[2]; case 4: ++b[2]; case 2: ++b[2]; break;
					case 7: ++b[7]; break;
					case 6: ++b[2]; ++b[3]; break;
					case 5: ++b[5]; break;
					default: break;
				}
		}
		if (a[ 2 ] == b[ 2 ]
		&& a[ 3 ] == b[ 3 ]
		&& a[ 5 ] == b[ 5 ]
		&& a[ 7 ] == b[ 7 ]) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}

