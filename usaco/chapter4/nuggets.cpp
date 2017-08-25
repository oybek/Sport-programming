
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

int gcd( int* a, int* b )
{
	int t = *a;
	for(; a != b; ++a )
		t = __gcd( t, *a );
	return t;
}

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

	if( a[0] == 1 || gcd( a, a+N ) > 1 )
	{
		cout << 0 << endl;
		return 0;
	}

	cando[0] = 1;
	for( int i = 0; i < cando.size(); ++i )
	{
		for( int j = 0; j < N; ++j )
			if( i >= a[j] && cando[i-a[j]] )
				cando[i] = 1;
	}

	for( int i = cando.size()-1; i > 0; --i )
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

