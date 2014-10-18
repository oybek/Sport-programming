
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

//#define SIZE 100001
//int sqrn[ SIZE ];

inline
bool is_sqr(int n)
{
	int s = floor(sqrt(n));
	return (s*s == n);
}

int main()
{
	/*
	int i, s;
	s = 4;
	sqrn[ 1 ] = 1;
	for ( i = 2; s < SIZE; ) {
		sqrn[ s ] = sqrn[ s+1-2*i ] + 1;
		++i;
		s += (2*i-1);
	}

	for ( i = 0; i < SIZE; ++i )
		if (sqrn[i] != 0)
			cout << i << ' ' << sqrn[i] << endl;
			*/

	int a, b;
	while ( 1 )
	{
		cin >> a >> b;
		if ( !a && !b ) break;

		if ( is_sqr(a) )
			cout << floor(sqrt(b)) - floor(sqrt(a)) + 1 << endl;
		else
			cout << floor(sqrt(b)) - floor(sqrt(a)) << endl;
	}

	return 0;
}

