
#include <set>
#include <map>
#include <bitset>
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

#define MLN 1000000
#define SIZE 80000

bitset<MLN+1> prime;
int primes[ SIZE ], primes_sz;
int ps_fac_n[ MLN+1 ];

/*int fac_n[ MLN+1 ];*/

void gen_sieve()
{
	prime.set();
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= MLN; ++i)
		if (prime[i])
			for (int j = i*i; j <= MLN; j += i)
				prime[j] = false;
}

int count_factors(int n)
{
	int ans = 0;
	for (int i = 0; primes[i]*primes[i] <= n;)
		if (n%primes[i] == 0)
		{
			++ans;
			n /= primes[i];
		} else
			++i;

	return (ans + (n > 1));
}

/*void gen_fac_n()*/
/*{*/
	/*for (int i = 2; i <= MLN; ++i)*/
		/*fac_n[i] = count_factors(i);*/
/*}*/

void gen_ps_fac_n()
{
	ps_fac_n[1] = 0;
	for (int i = 2; i <= MLN; ++i)
		ps_fac_n[i] = ps_fac_n[i-1] + count_factors(i);
}

int main()
{
	gen_sieve();
	for_(int, i, 2, MLN)
		if (prime[i])
			primes[ primes_sz++ ] = i;
	gen_ps_fac_n();

	int n;
	while (scanf("%d", &n) != EOF)
		cout << ps_fac_n[n] << endl;

	return 0;
}

