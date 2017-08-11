
/*
ID: aybek.h2
PROG: fence9
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd

int main()
{
#ifndef LOCAL
	freopen( "fence9.in", "rt", stdin );
	freopen( "fence9.out", "wt", stdout );
#endif

	int n, m, p;

	cin >> n >> m >> p;

	int s2 = p*m;

	if( s2 == 0 )
	{
		cout << 0 << endl;
	}
	else
	{
		cout << (s2 - (gcd(n, m) + gcd(m, abs(p-n)) + p-1) + 2)/2 << endl;
	}

	return 0;
}

