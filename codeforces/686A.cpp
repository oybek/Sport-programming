
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
	int n;
	i64 x;
	int sad = 0;

	scanf("%d%I64d", &n, &x);
	while( n-- )
	{
		char c;
		int d;
		scanf(" %c %d", &c, &d);

		if( c == '-' )
		{
			if( x >= d )
				x -= d;
			else
				++sad;
		}
		else
		{
			x += d;
		}
	}

	printf("%I64d %d\n", x, sad);

	return 0;
}

