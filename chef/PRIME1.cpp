
#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define SIZE 31623

vector<int> prime;
bitset<SIZE+1> is_prime;

void init_sieve()
{
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i*i <= SIZE; ++i)
		if (is_prime[i])
			for (int j = i*i; j <= SIZE; j += i)
				is_prime[j] = 0;
}

void init_prime()
{
	prime.push_back(2);
	for (int i = 3; i <= SIZE; i += 2)
		if (is_prime[i])
			prime.push_back(i);
}

bool is_primef(int n)
{
	if (n <= SIZE)
		return is_prime[n];

	int n_sqrt = int(sqrt(float(n)));
	for (int i = 0; i < int(prime.size()) && prime[i] <= n_sqrt; ++i)
		if (n%prime[i] == 0)
			return false;
	return true;
}

int main()
{
	int test_n;
	bool f1 = true;

	init_sieve();
	init_prime();

	scanf("%d", &test_n);

	while (test_n--)
	{
		int n, m;

		scanf("%d%d", &n, &m);

		if (f1) f1 = false;
		else puts("");

		for ( ; n <= m; ++n )
			if (is_primef(n))
				printf("%d\n", n);
	}

	return 0;
}

