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

#define N_MAX 5001
int N, a[N_MAX];

int main() {
	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; ++i)
			scanf("%d", a+i);
		sort(a, a+N);

		int count = 0;
		for (int i = 0; i < N; ++i)
			for (int j = i+1; j < N; ++j)
				count += upper_bound(a, a+N, a[i]+a[j]) - lower_bound(a, a+N, a[i]+a[j]);

		cout << count << endl;
	}

	return 0;
}

