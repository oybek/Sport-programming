
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

bool good[ 'Z'+1 ];

int main()
{
	string s;
	cin >> s;
	
	s = 'A' + s + 'A';

	good['A'] = good['E'] = good['I'] = good['O'] = good['U'] = good['Y'] = 1;

	int ans = 1;
	int j = 0;
	for( int i = 1; i < s.size(); ++i )
	{
		if( good[ s[ i ] ] )
		{
			ans = max( i-j, ans );
			j = i;
		}
	}
	ans = max( int(s.size())-j, ans );

	cout << ans << endl;

	return 0;
}

