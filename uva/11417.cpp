
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

#define N_MAX 501
int N, G[N_MAX];

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int main() {
	G[2] = 1;
	for (int i = 3; i < N_MAX; ++i) {
		G[i] = G[i-1];
		for (int j = 1; j < i; ++j)
			G[i] += gcd(j, i);
	}

	while (1) {
		cin >> N;
		if (!N)
			break;
		cout << G[N] << endl;
	}

	return 0;
}

