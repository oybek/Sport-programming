
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
#define X first
#define Y second

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

#define n_max 1001

int main()
{
	int a, b, n;
	pair<int, int> car[n_max];
	int v[n_max];

	scanf("%d%d%d", &a, &b, &n);
	for( int i = 0; i < n; ++i )
		scanf("%d%d%d", &(car[i].X), &(car[i].Y), &(v[i]));

	int ii = 0;
	for( int i = 1; i < n; ++i )
	{
		if(
			(sqr( car[i].X-a ) + sqr( car[i].Y-b ))*v[ii]*v[ii]
			<
			(sqr( car[ii].X-a ) + sqr( car[ii].Y-b ))*v[i]*v[i]
		)
			ii = i;
	}

	printf("%.10lf\n"
		, sqrt( sqr( car[ii].X-a ) + sqr( car[ii].Y-b ) ) / v[ii] );

	return 0;
}

