
#include <iostream>
#include <cmath>
using namespace std;

int prime[15000] = {2};
int last = 0;

bool is_prime(int n)
{
	if (n < 2) return false; int size = sqrt(n);
	for (int i = 2; i <= size; ++i) if (!(n%i)) return false;
	return true;
}

int get_prime(int n)
{
	int m;
	if (!prime[n])
		while(last < n) {
			for (m = prime[last]+1; !is_prime(m); ++m);
			prime[++last] = m;
		}

	return prime[n];
}

int main()
{
	int n, t;
	cin >> n;
	while (n--) {
		cin >> t;
		cout << get_prime(t-1) << endl;
	}

	return 0;
}

