
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
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
	int a1, a2;

	int ans = 0;
	scanf( "%d%d", &a1, &a2 );

	while( a1 > 0 && a2 > 0 )
	{
		if( a1 > a2 )
		{
			a1 -= 2;
			a2 += 1;

			if( a1 >= 0 )
				++ans;
		}
		else
		{
			a1 += 1;
			a2 -= 2;
			if( a2 >= 0 )
				++ans;
		}
	}

	printf( "%d", ans );

	return 0;
}

