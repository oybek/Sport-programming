
/*
ID: aybek.h2
PROG: nuggets
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define N_MAX 11

int N;
int a[N_MAX];
bitset< 256*256-512+1 > cando;

int main()
{
#ifndef LOCAL
	freopen( "nuggets.in", "rt", stdin );
	freopen( "nuggets.out", "wt", stdout );
#endif

	cin >> N;
	for( int i = 0; i < N; ++i )
		cin >> a[i];

	sort( a, a+N );

	cando[0] = 1;
	for( int i = 0; i < cando.size(); ++i )
	{
		for( int j = 0; j < N; ++j )
			if( i >= a[j] && cando[i-a[j]] )
				cando[i] = cando[i-a[j]];
	}

	if( !cando[ cando.size()-1 ] )
	{
		cout << 0 << endl;
		return 0;
	}

	for( int i = cando.size()-1; i >= a[0]; --i )
	{
		if( !cando[i] )
		{
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
	return 0;
}

