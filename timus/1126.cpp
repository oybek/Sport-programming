
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

#define N_MAX 25001
int N, M, a[N_MAX];
map<int, int> range;

int main() {
	cin >> M;
	while (1) {
		int t;
		cin >> t;
		if (t == -1)
			break;
		a[N++] = t;
	}

	for (int i = 0; i < M; ++i) {
		if (range.find(a[i]) != range.end()) {
			++range[a[i]];
		} else {
			range[a[i]] = 1;
		}
	}

	cout << range.rbegin()->first << endl;

	for (int i = M; i < N; ++i) {
		if (range[a[i-M]] == 1)
			range.erase(a[i-M]);
		else
			--range[a[i-M]];

		if (range.find(a[i]) != range.end()) {
			++range[a[i]];
		} else {
			range[a[i]] = 1;
		}

		cout << range.rbegin()->first << endl;
	}

	return 0;
}

