
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
	int a, b, c;
	scanf( "%d%d%d", &a, &b, &c );

	if( a == b )
	{
		printf("YES\n");
		return 0;
	}

	if( c == 0 )
	{
		printf( "%s\n", a == b ? "YES" : "NO" );
	}
	else if( c > 0 )
	{
		if( a >= b )
			printf( "NO\n" );
		else
			printf( "%s\n", (b-a)%c == 0 ? "YES" : "NO" );
	}
	else if( c < 0 )
	{
		if( a <= b )
			printf( "NO\n" );
		else
			printf( "%s\n", (a-b)%c == 0 ? "YES" : "NO" );
	}

	return 0;
}

