
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define SIZE 1000
#define MOD 1000000009
#define n_MAX 10001

bitset<SIZE> prime;
vector<int> primes;
int n, dp[100][n_MAX];

void init_prime() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i < SIZE; ++i)
		if (prime[i])
			for (int j = i*i; j < SIZE; j += i)
				prime[j] = 0;
}

int main() {
	init_prime();
	primes.reserve(200);
	for (int i = 2; i < SIZE; ++i)
		if (prime[i] && i > 99)
			primes.push_back(i);

	for (int i = 0; i < primes.size(); ++i)
		++dp[primes[i]%100][3];

	cin >> n;
	for (int i = 4; i <= n; ++i)
		for (int j = 0; j < primes.size(); ++j) {
			int t = primes[j];
			dp[t%100][i] += dp[t/10][i-1];
			dp[t%100][i] %= MOD;
		}

	int ans = 0;
	for (int i = 0; i <= 99; ++i) {
		ans += dp[i][n];
		ans %= MOD;
	}

	cout << ans << endl;

	return 0;
}

