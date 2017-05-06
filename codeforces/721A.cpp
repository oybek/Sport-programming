
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
	string s;
	cin >> s >> s;

	vector<int> ans;

	for( int i = 0; i < s.size(); ++i )
	{
		if( s[ i ] == 'B' )
		{
			int count = 0;
			for( ; i < s.size() && s[ i ] == 'B'; ++i )
				++count;
			ans.push_back( count );
		}
	}

	cout << ans.size() << endl;
	for( int x : ans )
		cout << x << ' ';
	if( ans.size() > 0 )
		cout << endl;

	return 0;
}

