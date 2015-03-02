
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

int main() {
	uint64 N;
	for (int test_i = 1; ; ++test_i) {
		/* input stage */
		cin >> N;
		if (N == 0)
			break;

		uint64 N_sqrt = floor(sqrt(8*N + 9));
		cout << "Case " << test_i << ": " << (3 + N_sqrt)/2 + (SQR(N_sqrt) < 8*N + 9) << endl;
	}

	return 0;
}

