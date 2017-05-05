
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

	vector<int> even, odd;
	even.reserve(n);
	odd.reserve(n);

	while( n-- )
	{
		int t;
		cin >> t;
		if( t%2 )
			odd.push_back(t);
		else
			even.push_back(t);
	}

	i64 odd_sum = accumulate( all(odd), 0ll );

	if( odd_sum%2 )
	{
		cout << odd_sum - *min_element( all(odd) ) + accumulate( all(even), 0ll ) << endl;
	}
	else
	{
		cout << odd_sum + accumulate( all(even), 0ll ) << endl;
	}


	return 0;
}

