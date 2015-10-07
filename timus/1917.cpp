
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

int div_n(int n) {
	int count = 0;
	for (int i = 1; i*i <= n; ++i)
		if (n%i == 0)
			++count;
	return count;
}

int main() {
	int M, N, K;
	cin >> M >> N >> K;
	for (int L = 1; L <= 10000; ++L) {
		if (div_n(L) == N && div_n(L-K) == M) {
			cout << L << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}

