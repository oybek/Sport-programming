
#include<stdio.h>

#define min(x,y) ((x)<(y)? x:y)

int main() {
	int i, a = 1, b = 1, c = 1, x, y, z;
	long u[1520];

	u[1] = u[2]= u[3] = 1;

	for ( i = 2; i <= 1500; ++i ) {

		x = 2 * u[a];
		y = 3 * u[b];	
		z = 5 * u[c];

		u[i] = min(x, min(y, z));
		if ( u[i] == x ) a++;
		if ( u[i] == y ) b++;
		if ( u[i] == z ) c++;
	}

	printf("The 1500'th ugly number is %ld.",u[1500]);

	return 0;
}

