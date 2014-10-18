
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 1000 + 1

vector<int> primes;

void gen_primes() {
	bool is_prime[ MAX_N ];
	fill(is_prime, is_prime + MAX_N, true);

	is_prime[ 0 ] = false;
	int i, j;
	for ( i = 2; i*i <= MAX_N; ++i )
		if ( is_prime[ i ] )
			for ( j = i*i; j <= MAX_N; j += i )
				is_prime[ j ] = false;

	primes.push_back(1);
	for ( i = 2; i <= MAX_N; ++i )
		if ( is_prime[i] )
			primes.push_back(i);
}

// find greatest number in primes[] which is less or equal to n
// and return it's index

int main() {
	gen_primes();

	return 0;
}

