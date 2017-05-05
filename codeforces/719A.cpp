
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
	cin >> n;
	if( n == 1 )
	{
		int t;
		cin >> t;

		if( t == 15 )
			cout << "DOWN";
		else if( t == 0 )
			cout << "UP";
		else
			cout << -1;

		cout << endl;
	}
	else
	{
		vector<int> a( n );
		for( int& x : a )
			cin >> x;

		if( a[ a.size()-1 ] == 0 )
			cout << "UP";
		else if( a[ a.size()-1 ] == 15 )
			cout << "DOWN";
		else if( a[ a.size()-1 ] > a[ a.size()-2 ] )
			cout << "UP";
		else if( a[ a.size()-1 ] < a[ a.size()-2 ] )
			cout << "DOWN";
		else
			cout << -1;
	}

	return 0;
}

