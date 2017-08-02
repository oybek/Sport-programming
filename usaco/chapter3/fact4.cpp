
/*
ID: aybek.h2
PROG: fact4
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef LOCAL
	freopen( "fact4.in", "rt", stdin );
	freopen( "fact4.out", "wt", stdout );
#endif

	int N;
	cin >> N;

	int ans = 1;
	for( int i = 1; i <= N; ++i )
	{
		ans *= i;
		while( ans%10 == 0 )
			ans /= 10;
		ans %= 100000;
	}

	while( ans%10 == 0 )
		ans /= 10;
	cout << ans%10 << endl;

	return 0;
}

