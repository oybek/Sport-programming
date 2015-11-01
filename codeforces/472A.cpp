
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
#include <numeric>
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

#define pmax 1000001
bitset<pmax> prime;
void init() {
	prime.set();
	prime[0] = prime[1] = 0;
	for (int i = 2; i*i < pmax; ++i)
		if (prime[i])
			for (int j = i*i; j < pmax; j += i)
				prime[j] = 0;
}

int main() {
	init();
	int n;
	cin >> n;
	for (int i = 4; i < pmax; i += 2)
		if (!prime[n-i]) {
			cout << min(n-i, i) << ' ' << max(n-i, i);
			break;
		}

	return 0;
}

