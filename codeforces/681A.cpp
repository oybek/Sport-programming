
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
	scanf( "%d", &n );
	while( n-- )
	{
		char s[99];
		int a, b;
		scanf( "%s %d %d", s, &a, &b );

		if( a >= 2400 && b > a )
		{
			printf( "YES\n" );
			return 0;
		}
	}

	printf( "NO\n" );
	return 0;
}

