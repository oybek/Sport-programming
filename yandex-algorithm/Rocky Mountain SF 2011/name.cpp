
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

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int lyndon_word(const char *a, int n)
{
  int i = 0, j = 1, k;
  while (j < n) {
    // Invariant: i < j and indices in [0,j) \ i cannot be the first optimum
    for (k = 0; k < n && a[(i+k)%n] == a[(j+k)%n]; k++);
    if (a[(i+k)%n] <= a[(j+k)%n]) {
      // if k < n
      //   foreach p in [j,j+k], s_p > s_{p-(j-i)}
      //   => [j,j+k] are all suboptimal
      //   => indices in [0,j+k+1) \ i are suboptimal
      // else
      //   None of [j,j+k] is the first optimum
      j += k+1;
    } else {
      // foreach p in [i,i+k], s_p > s_{p+(j-i)}
      // => [i,i+k] are all suboptimal
      // => [0,j) and [0,i+k+1) are suboptimal
      // if i+k+1 < j
      //   j < j+1 and indices in [0,j+1) \ j are suboptimal
      // else
      //   i+k+1 < i+k+2 and indices in [0,i+k+2) \ (i+k+1) are suboptimal
      i += k+1;
      if (i < j)
        i = j++;
      else
        j = i+1;
    }
  }
  // j >= n => [0,n) \ i cannot be the first optimum
  return i;
}

int main()
{
	string s;

	//
	while( cin >> s )
	{
		//
		for( int i = 0; i < s.size(); ++i )
			s[ i ] -= '0';

		//
		char tmp = s[ 0 ];
		for( int i = 0; i+1 < s.size(); ++i )
		{
			s[ i ] = s[ i+1 ] - s[ i ];
			if( s[ i ] < 0 )
				s[ i ] = 8 + s[ i ];
		}
		*s.rbegin() = tmp - *s.rbegin();
		if( *s.rbegin() < 0 )
		{
			*s.rbegin() = 8 + *s.rbegin();
		}

		//
		for( int i = 0; i < s.size(); ++i )
		{
			s[ i ] += '0';
		}
		int i = lyndon_word( s.c_str(), s.size() );
		cout << s.substr( i ) << s.substr( 0, i ) << endl;
	}

	return 0;
}

