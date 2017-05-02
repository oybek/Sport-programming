
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

bool good( const vector<int>& a )
{
	for( int i = 0; i < a.size(); ++i )
	{
		if( a[ i ] != a[ 0 ] )
			return false;
	}
	return true;
}

bool fuck( int test )
{
	int N;
	vector<int> a;

	cin >> N;
	if( N == 0 )
		return false;

	a.resize( N );
	for( vector<int>::iterator it = a.begin(); it != a.end(); ++it )
		cin >> *it;

	cout << "Case " << test << ": ";
	for( int i = 0; i <= 1000; ++i )
	{
		if( good( a ) )
		{
			cout << i << " iterations\n";
			return true;
		}

		int tmp = a[ 0 ];
		for( int j = 0; j+1 < a.size(); ++j )
			a[ j ] = abs( a[ j ] - a[ j+1 ] );
		a[ a.size()-1 ] = abs( a[ a.size()-1 ] - tmp );
	}
	cout << "not attained\n";
	return true;
}

int main()
{
	int test = 0;
	while( fuck( ++test ) );

	return 0;
}

