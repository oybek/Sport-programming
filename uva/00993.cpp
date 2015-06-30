
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define SIZE 32000
bitset<SIZE> is_prime;
vector<int> primes;

void init_is_prime() {
	is_prime.set();
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i*i < SIZE; ++i)
		if (is_prime[i])
			for (int j = i*i; j < SIZE; j += i)
				is_prime[j] = false;
}

void init_primes() {
	for (int i = 0; i < SIZE; ++i)
		if (is_prime[i])
			primes.push_back(i);
}

void minimize(vector<int> & digit) {
	sort(digit.begin(), digit.end());
	for (int i = digit.size()-1; i >= 0; --i)
		for (int j = i-1; j >= 0; --j)
			if (digit[i] * digit[j] < 10) {
				digit[i] *= digit[j];
				digit.erase(digit.begin()+j);
				sort(digit.begin(), digit.end());
			}
}

void show(const vector<int> & v) {
	for (int i = 0; i < int(v.size()); ++i)
		cout << v[i] << ' ';
	cout << endl;
}

void factorize(int n, vector<int> & cn) {
	for (int i = 0; i < int(primes.size()); )
		if (n % primes[i] == 0) {
			cn.push_back(primes[i]);
			n /= primes[i];
		} else
			++i;
	if (n > 1)
		cn.push_back(n);
}

bool is_good(const vector<int> & cn) {
	for (int i = 0; i < int(cn.size()); ++i)
		if (cn[i] > 9)
			return false;
	return true;
}

void solve(int n) {
	if (n == 1) {
		cout << "1\n";
		return;
	} else
	if (n == 0) {
		cout << "10\n";
		return;
	}

	vector<int> cn;
	factorize(n, cn);

	show(cn);

	if (!is_good(cn)) {
		cout << "-1\n";
	} else {
		minimize(cn);
		for (int i = 0; i < int(cn.size()); ++i)
			cout << cn[i];
		cout << endl;
	}
}

int main() {
	init_is_prime();
	init_primes();

	int test_n;
	cin >> test_n;
	while (test_n--) {
		int n;
		cin >> n;
		solve(n);
	}

	return 0;
}

