
/*
ID: aybek.h2
PROG: rockers
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define N_MAX 21

int N, T, M;
int a[N_MAX];

int count_setbits( int n )
{
	int cnt = 0;
	for(; n; n >>= 1 )
		cnt += n&1;
	return cnt;
}

int get_written_songs_num( int subset )
{
	int m = M;
	int t = T;

	int songs_written = 0;

	for( int i = 0; i < N; ++i )
	{
		if( subset&(1<<i) )
		{
			if( a[i] <= t )
			{
				t -= a[i];
				++songs_written;
			}
			else
			{
				// no disks left
				if( m == 1 )
					break;

				// get new disk
				t = T;
				--m;
				--i;
			}
		}
	}

	return songs_written;
}

int main()
{
#ifndef LOCAL
	freopen( "rockers.in", "rt", stdin );
	freopen( "rockers.out", "wt", stdout );
#endif

#ifdef LOCAL
	assert( count_setbits( 3 ) == 2 );
	assert( count_setbits( 5 ) == 2 );
	assert( count_setbits( 8 ) == 1 );
	assert( count_setbits( 31 ) == 5 );
#endif

	cin >> N >> T >> M;
	for( int i = 0; i < N; ++i )
		cin >> a[i];

	int ans_subset;
	int ans = 0;
	// bruteforce >:(
	for( int subset = 0; subset < (1<<N); ++subset )
	{
		int wanted = count_setbits( subset );
		int written = get_written_songs_num( subset );
		if( written == wanted )
		{
			if( ans < written )
			{
				ans_subset = subset;
			}
			ans = max( ans, written );
		}
	}

#ifdef LOCAL
	cout << bitset<20>(ans_subset) << endl;
#endif

	cout << ans << endl;

	return 0;
}

