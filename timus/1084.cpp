
/*
http://acm.timus.ru/problem.aspx?space=1&num=1084
*/

#include <cmath>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;
	double a, r, x;

	cin >> a >> r;

	if ( 2*r*r >= a*a ) {
		printf( "%.3f\n", a*a );
	} else
	if ( 2*r <= a ) {
		printf( "%.3f\n", M_PI*r*r );
	} else {
		x = acos( a/2.0/r );
		printf( "%.3f\n"
			, M_PI*r*r - 4*( x*r*r - sin(x)*a*r*0.5) );
	}

	return 0;
}

