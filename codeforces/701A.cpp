
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

	vector< pair<int, int> > a( n );
	for( int i = 0; i < a.size(); ++i )
	{
		cin >> a[ i ].first;
		a[ i ].second = i+1;
	}

	sort( all(a) );

	for( int i = 0; i < a.size()/2; ++i )
	{
		cout << a[ i ].second << ' ' << a[ a.size()-1-i ].second << endl;
	}

	return 0;
}

