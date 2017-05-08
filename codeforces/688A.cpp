
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
	int n, d, ans = 0, cur = 0;
	scanf( "%d%d", &n, &d );

	while( d-- )
	{
		string s;
		cin >> s;

		if( count( all(s), '1' ) == s.size() )
		{
			ans = max( ans, cur );
			cur = 0;
		}
		else
		{
			++cur;
		}
	}
	ans = max( ans, cur );

	cout << ans << endl;

	return 0;
}

