
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
	char s1[10], s2[10];
	scanf("%d %s %s", &n, s1, s2);

	if( s2[0] == 'w' )
	{
		printf("%d", ( n == 5 || n == 6 ? 53 : 52 ));
	}
	else
	{
		if( n == 31 )
		{
			puts("7");
		}
		else if( n == 30 )
		{
			puts("11");
		}
		else
		{
			puts("12");
		}
	}

	return 0;
}

