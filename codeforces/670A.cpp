
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

	int a, b;
	a = b = n/7*2;

	switch( n%7 )
	{
		case 0: break;
		case 1: a += 0; b += 1; break;
		case 2: a += 0; b += 2; break;
		case 3: a += 0; b += 2; break;
		case 4: a += 0; b += 2; break;
		case 5: a += 0; b += 2; break;
		case 6: a += 1; b += 2; break;
	}

	printf( "%d %d", a, b );

	return 0;
}

