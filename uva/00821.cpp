
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

#define N_MAX 101

int N,
	a[N_MAX][N_MAX];

void floyd_warshall() {
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
}

void show_a() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[i][j] == INF) {
				cout << setw(4) << "INF";
			} else {
				cout << setw(4) << a[i][j];
			}
		}
		cout << endl;
	}
}

int main() {
	int x, y;
	for (int test_i = 1; ; ++test_i) {
		/* prepare stage */
		N = 0;
		for (int i = 0; i < N_MAX; ++i)
			for (int j = 0; j < N_MAX; ++j)
				a[i][j] = (i == j ? 0 : INF);

		/* Input stage */
		cin >> x >> y;
		if (!x && !y) break;

		do {
			N = max(max(x, y), N);
			a[x-1][y-1] = 1;
			cin >> x >> y;
		} while (x || y);

		/* solve */
		floyd_warshall();

		float sum = 0.0;
		int count = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j || a[i][j] == INF) continue;
				sum += a[i][j];
				++count;
			}
		}

		cout	<< "Case " << test_i << ": average length between pages = "
				<< fixed << setprecision(3)
				<< sum / count << " clicks\n";
	}

	return 0;
}

