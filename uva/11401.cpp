
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

uint64 solve(uint64 n) {
	if (n <= 3)
		return 0;
	else {
		n -= 2;
		return (4*n*n*n + 6*n*n - 4*n - 3 + 3*(n%2 ? -1 : 1)) / 48;
	}
}

int n;
#define SIZE 1000001

int main() {
	while (1) {
		cin >> n;
		if (n < 3)
			break;
		cout << solve(n) << endl;
	}

	return 0;
}

