
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define N_MAX 1000+1
#define t_MAX 14+1

bool comp(int a, int b) {
	return to_string(a) < to_string(b);
}

bool is_prime(int n) {
	if (n  < 2) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; ++i) {
		if (n%i == 0)
			return false;
	}
	return true;
}

void show(const vector<int>& a) {
	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << ' ';
	cout << endl;
}

int main() {
	vector<int> primes; primes.reserve(200);
	for (int i = 2; i < 300; ++i) {
		if (is_prime(i)) {
			primes.push_back(i);
		}
	}
	sort(all(primes), comp);

	show(primes);

#ifdef DEBUG
	cout << primes.size() << endl;
	for (int i = 0; i < primes.size(); ++i)
		cout << primes[i] << endl;
#endif

	vector<int> sol[N_MAX][t_MAX];

	for (int prime : primes) {
		sol[prime][1].push_back(prime);
	}

	for (int prime: primes) {
		for (int i = 2; i < t_MAX; ++i) {
			for (int n = 0; n < N_MAX; ++n) {
				if (n-prime >= 0 && sol[n-prime][i-1].size() == i-1) {
					sol[n][i] = sol[n-prime][i-1];
					sol[n][i].push_back(prime);
				}
			}
		}
	}

	show(sol[2][1]);
	show(sol[3][1]);
	show(sol[4][2]);
	show(sol[5][2]);
	show(sol[100][4]);
	show(sol[1000][14]);
	show(sol[1000][10]);

	return 0;
}

