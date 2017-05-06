
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

#define SIEVE_SIZE 100000
bitset< SIEVE_SIZE > sieve;
void init_sieve()
{
	sieve.set();
	sieve[0] = sieve[1] = false;
	for (int i = 2; i*i <= SIEVE_SIZE; ++i)
	{
		if (sieve[i])
		{
			for (int j = i*i; j <= SIEVE_SIZE; j += i)
				sieve[j] = false;
		}
	}
}

vector<int> primes;
void init_primes()
{
	primes.reserve(SIEVE_SIZE);
	for (int i = 2; i < SIEVE_SIZE; ++i)
	{
		if (sieve[i])
			primes.push_back(i);
	}
}

int main()
{
	init_sieve();
	init_primes();

	int n, k;
	cin >> n >> k;

	int i = 0;
	vector<int> a;
	for( ;; )
	{
		if( a.size() == k-1 && n > 1 )
		{
			for( int x : a )
				cout << x << ' ';
			cout << n << endl;
			break;
		}

		if( n < primes[ i ] )
		{
			cout << -1 << endl;
			break;
		}

		if( n % primes[ i ] == 0 )
		{
			a.push_back( primes[ i ] );
			n /= primes[ i ];
		}
		else
		{
			++i;
		}
	}

	return 0;
}

