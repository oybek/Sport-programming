
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;


#define SIEVE_SIZE 1001

bitset< SIEVE_SIZE > is_prime;

void init_is_prime()
{
	is_prime.set();
	is_prime[0] = is_prime[1] = false;
	for( int i = 2; i*i < SIEVE_SIZE; ++i )
		if( is_prime[i] )
			for( int j = i*i; j < SIEVE_SIZE; j += i )
				is_prime[j] = false;
	is_prime[1] = true;
}

int main()
{
	init_is_prime();

	int N, C;
	while( cin >> N >> C )
	{
		vector<int> primes; primes.resize(0);

		for( int i = 1; i <= N; ++i )
			if( is_prime[i] )
				primes.push_back( i );

		vector<int> ans; ans.resize(0);

		if( primes.size()%2 )
		{
			int i;
			int j;
			int n = 2*C-1;

			i = j = primes.size()/2;

			ans.push_back( primes[i] ); n--;

			while( (n > 0) && (--i >= 0) && (++j < primes.size()) )
			{
				ans.push_back( primes[i] );
				ans.push_back( primes[j] );

				n -= 2;
			}
		}
		else
		{
			int i;
			int j;
			int n = 2*C;

			i = primes.size()/2-1;
			j = primes.size()/2;

			ans.push_back( primes[i] );
			ans.push_back( primes[j] );

			n -= 2;

			while( (n > 0) && (--i >= 0) && (++j < primes.size()) )
			{
				ans.push_back( primes[i] );
				ans.push_back( primes[j] );

				n -= 2;
			}
		}

		sort( all(ans) );

		cout << N << ' ' << C << ':';
		for( auto x : ans )
			cout << ' ' << x;
		cout << endl << endl;
	}

	return 0;
}

