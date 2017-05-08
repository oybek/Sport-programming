
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

#define dp_size 151
int dp[dp_size][dp_size];

int fuck( int a1, int a2, int ans )
{
	if( a1 < 0 || a2 < 0 )
		return ans-1;

	if( a1 == 0 || a2 == 0 )
		return ans;

	if( dp[a1][a2] != -1 )
		return dp[a1][a2];

	return dp[a1][a2] = max( fuck( a1+1, a2-2, ans+1 ), fuck( a1-2, a2+1, ans+1) );
}

int main()
{
	int a1, a2;

	for( int i = 0; i < dp_size; ++i )
		for( int j = 0; j < dp_size; ++j )
			dp[i][j] = -1;

	scanf( "%d %d", &a1, &a2 );
	printf( "%d\n", fuck( a1, a2, 0 ) );

	return 0;
}

