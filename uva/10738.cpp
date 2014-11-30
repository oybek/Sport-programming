
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define SIZE 1000000

bitset<SIZE+1> was;
bitset<SIZE+1> prime;
vector<int> primes;
int mu[ SIZE+ 1];
int sum[ SIZE+1 ];

void gen_sieve()
{
	prime.set();
	prime[0] = prime[1] = 0;

	for (int i = 2; i*i <= SIZE; ++i)
		if (prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				prime[j] = 0;
}

typedef unsigned long long uint64;

bool backtrack(uint64 n, int fn, int i)
{
	if (n > SIZE)
		return false;
	else
	{
		if (fn%2) {
			mu[ n ] = -1;
			for (; i < primes.size(); ++i)
				if (backtrack(n*primes[i], fn+1, i+1))
					break;
		} else {
		}
	}
}

/*int factorize(int n)*/
/*{*/
	/*if (n == 1)*/
		/*return 1;*/

	/*if (prime[n])*/
		/*return -1;*/

	/*was.reset();*/
	/*int fn = 0, i;*/
	/*for (i = 0; (i <= SIZE) && (primes[i]*primes[i] <= n);)*/
		/*if (n % primes[i] == 0) {*/
			/*if (was[ primes[i] ]) {*/
				/*return 0;*/
			/*} else {*/
				/*++fn;*/
				/*was[ primes[i] ] = 1;*/
				/*n /= primes[i];*/
			/*}*/
		/*} else {*/
			/*++i;*/
		/*}*/

	/*if (prime[n]) {*/
		/*if (was[n]) {*/
			/*return 0;*/
		/*} else {*/
			/*++fn;*/
		/*}*/
	/*}*/

	/*return (fn%2 ? -1: 1);*/
/*}*/

int main()
{
	primes.reserve(100000);
	gen_sieve();
	for (int i = 2; i <= SIZE; ++i)
		if (prime[i])
			primes.push_back(i);

	sum[1] = 1;
	for (int i = 2; i <= SIZE; ++i)
		sum[i] = sum[i-1] + factorize(i);

	return 0;
}

