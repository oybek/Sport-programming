
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

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

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n, a, b, t = 0;

	cin >> n;
	while( n-- )
	{
		cin >> a >> b;
		if( a > b ) ++t;
		if( a < b ) --t;
	}
	cout <<
		( t == 0
		? "Friendship is magic!^^"
		: t < 0
			? "Chris"
			: "Mishka" );

	return 0;
}

