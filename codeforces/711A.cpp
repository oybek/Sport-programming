
/* Use <F5> to compile & run program
 * file.in will be redirected to stdin
 * in file.out you'll get program stdout
 */

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

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	int n;
	bool yes = false;

	vector<string> ans;

	cin >> n;
	while( n-- )
	{
		string s;
		cin >> s;

		if( !yes )
		{
			if( s[ 0 ] == 'O' && s[ 1 ] == 'O' )
			{
				s[ 0 ] = s[ 1 ] = '+';
				yes = true;
			}
		}

		if( !yes )
		{
			if( s[ 3 ] == 'O' && s[ 4 ] == 'O' )
			{
				s[ 3 ] = s[ 4 ] = '+';
				yes = true;
			}
		}

		ans.push_back( s );
	}

	cout << ( yes ? "YES" : "NO" ) << endl;
	if( yes )
	{
		for( string s : ans )
			cout << s << endl;
	}

	return 0;
}

