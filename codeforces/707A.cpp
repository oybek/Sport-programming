
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
	char c;
	bool bw = true;
	while( cin.get( c ) )
	{
		if( isalpha( c ) )
		{
			if( c != 'B' && c != 'W' && c != 'G' )
			{
				bw = false;
				break;
			}
		}
	}
	cout << ( bw ? "#Black&White" : "#Color" );

	return 0;
}

