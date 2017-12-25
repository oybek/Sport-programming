
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	int test_num;
	cin >> test_num;

	while( test_num-- )
	{
		char c, m, n;
		cin >> c >> m >> n;

		int ans;
		switch( c )
		{
			case 'r': ans = min(m, n); break;
			case 'k': ans = SQR(min(m, n))/2 + SQR(min(m, n))%2; break;
			case 'Q':
			{
				ans = min(m, n);
				if( ans == 2 )
					ans = 1;
				else if( ans == 3 )
					ans = 2;
				break;
			}
			case 'K': break;
			default: assert(false);
		}
	}

	return 0;
}

