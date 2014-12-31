
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

/*find first 100000 twin primes*/

#define SIZE 20000000
bitset<SIZE+1> prime;

void init_prime()
{
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i <= SIZE; ++i)
		if (prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = 0;
}

const int twin_sz_max = 110000;

int twin_sz = 0,
	twin[ twin_sz_max ];

int main()
{
	init_prime();

	++twin_sz;
	for (int i = 3; i < SIZE; i += 2)
		if (prime[i] && i+2 < SIZE && prime[i+2])
			twin[ twin_sz++ ] = i;

	int n;
	while (scanf("%d", &n) != EOF)
	{
		assert(n > 0);
		printf("(%d, %d)\n", twin[n], twin[n]+2);
	}

	return 0;
}

