
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

int main()
{
	int n, k1, k2, test = 0;
	vector<int> lowest; lowest.reserve( 101 );
	vector<int> highest; highest.reserve( 101 );
	vector< pair< int, int > > a;
	a.reserve( 1000005 );

	for( ;; )
	{
		//
		cin >> n >> k1 >> k2;
		if( n == 0 && k1 == 0 && k2 == 0 )
		{
			break;
		}

		//
		a.resize( n );
		for( int i = 0; i < n; ++i )
		{
			cin >> a[ i ].first;
			a[ i ].second = i+1;
		}

		//
		sort( a.begin(), a.end() );

		//
		lowest.resize( 0 );
		for( int i = 0; i < k1; ++i )
		{
			lowest.push_back( a[ i ].second );
		}

		//
		highest.resize( 0 );
		for( int i = 0; i < k2; ++i )
		{
			highest.push_back( a[ a.size()-1-i ].second );
		}

		//
		sort( lowest.begin(), lowest.end() );
		sort( highest.rbegin(), highest.rend() );

		//
		cout << "Case " << ++test << endl;
		for( int i = 0; i < lowest.size(); ++i )
		{
			cout << lowest[ i ] << ' ';
		}
		cout << endl;
		{
			for( int i = 0; i < highest.size(); ++i )
				cout << highest[ i ] << ' ';
		}
		cout << endl;
	}

	return 0;
}

