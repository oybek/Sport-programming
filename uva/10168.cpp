
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 10 ## 000 ## 001
#define PRIMEN 700 ## 000

vector<int> primes;
bool not_prime[ MAXN ];

bool finished = false;
inline
void backtrack( const int n, vector<int> & ind )
{
	if (n < 0)
		return;

	if (ind.size() == 3) {
		if ( (finished = !not_prime[n]) )
			ind.push_back(n);
		return;
	}

	for ( register auto e : primes ) {
		ind.push_back(e);
		backtrack( n-e, ind );
		if ( finished )
			return;
		ind.pop_back();
	}
}

inline
void gen_primes( register int n)
{
	register int i, j;
	not_prime[0] = not_prime[1] = true;

	for ( i = 2; i*i <= n; ++i )
		if ( !not_prime[ i ] )
			for ( j = i*i; j <= n; j += i)
				not_prime[ j ] = true;

	for ( i = 2; i <= n; ++i )
		if ( !not_prime[ i ] )
			primes.push_back(i);
}

int main()
{
	primes.reserve( PRIMEN );
	gen_primes( MAXN );

	int n;
	vector<int> num; num.reserve( 4 );
	while ( cin >> n )
	{
		num.resize(0);
		backtrack( n, num );
		for ( register auto e : num )
			cout << e << ' ';
		cout << endl;
	}

	return 0;
}

