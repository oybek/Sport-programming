
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

#define dp_SIZE 10000
uint64 dp[dp_SIZE];

int main() {
	dp[0] = 1;
	for (int i = 1; ; ++i) {
		int i3 = i*i*i;
		if (i3 > dp_SIZE)
			break;
		for (int j = i3; j < dp_SIZE; ++j)
			dp[j] += dp[j-i3];
	}

	int n;
	while (cin >> n) {
		cout << dp[n] << endl;
	}

	return 0;
}

