
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define MOD 1000000007
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int n, a, b;
int ac, bc;
int dp[ 50001 ];

int main()
{
	cin >> n >> a >> b;

	dp[ 0 ] = 2;
	ac = bc = 1;
	for( int i = 1; i < n; ++i )
	{
		if( ac < a )
		{
			if( bc < b )
			{
				dp[ i ] = (dp[ i-1 ]*2)%MOD;
				++ac;
				++bc;
			}
			else
			{
				dp[ i ] = (dp[ i-1 ]+1)%MOD;
				++ac;
				bc = 0;
			}
		}
		else
		{
			if( bc < b )
			{
				dp[ i ] = (dp[ i-1 ]+1)%MOD;
				ac = 0;
				++bc;
			}
			else
			{
				// impossible part
				assert( false );
			}
		}
	}

	cout << dp[ n-1 ] << endl;

	return 0;
}

