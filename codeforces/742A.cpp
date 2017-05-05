
/* Use <F5> to compile & run program
 * file.in will be redirected to stdin
 * in file.out you'll get program stdout
 */

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
	cin >> n;
	if( n == 0 )
	{
		cout << 1 << endl;
		return 0;
	}
	switch( n%4 )
	{
		case 1: cout << 8 << endl; break;
		case 2: cout << 4 << endl; break;
		case 3: cout << 2 << endl; break;
		case 0: cout << 6 << endl; break;
	}

	return 0;
}

