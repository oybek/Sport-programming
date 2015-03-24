
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

#define N_MAX 1000001

int N, M, a[N_MAX], tmp, ans;

int main() {
	while (true) {
		cin >> N >> M;
		if (!N && !M)
			break;

		ans = 0;
		for (int i = 0; i < N; ++i)
			cin >> a[i];
		for (int i = 0; i < M; ++i) {
			cin >> tmp;
			if (binary_search(a, a+N, tmp)) {
				++ans;
			}
		}
		cout << ans << endl;
	}

	return 0;
}

