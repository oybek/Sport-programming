
/*
ID: aybek.h2
PROG: ratios
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

// very bad solution
int main()
{
#ifndef LOCAL
	freopen( "ratios.in", "rt", stdin );
	freopen( "ratios.out", "wt", stdout );
#endif

	int a[4];
	int b[4];
	int c[4];

	for( int i = 0; i < 4; ++i )
		cin >> a[i] >> b[i] >> c[i];

	int mx = 101, my = 101, mz = 101;
	for( int x = 0; x <= 100; ++x )
	for( int y = 0; y <= 100; ++y )
	for( int z = 0; z <= 100; ++z )
	{
		if( !x && !y && !z )
			continue;

		int s1 = x*a[1] + y*a[2] + z*a[3];
		int s2 = x*b[1] + y*b[2] + z*b[3];
		int s3 = x*c[1] + y*c[2] + z*c[3];

		if( (!a[0] || s1%a[0] == 0) &&
			(!b[0] || s2%b[0] == 0) &&
			(!c[0] || s3%c[0] == 0) &&
			s1*b[0] == s2*a[0] &&
			s1*c[0] == s3*a[0] &&
		 	x+y+z < mx+my+mz )
		{
			mx = x;
			my = y;
			mz = z;
		}
	}

	if( mx == 101 )
		cout << "NONE\n";
	else
		cout << mx << ' ' << my << ' ' << mz << ' ' << (mx*a[1] + my*a[2] + mz*a[3])/a[0] << endl;

	return 0;
}

