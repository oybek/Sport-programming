
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

int ans( i64 n )
{
	if( n <= 0 )
		return 1;
	if( n%2 )
		return 5*ans( n/2 )%100;
	else
		return 5*ans( n-1 )%100;
}

int main()
{
	puts("25");
	return 0;

	i64 n;
	cin >> n;
	printf( "%d\n", ans( n ) );

	return 0;
}

