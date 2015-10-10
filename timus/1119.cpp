
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

#define N_MAX 1001

int N, M;
float a[N_MAX][N_MAX];
const float S = sqrtf(2)*100;

int main() {
	int K;
	cin >> N >> M
		>> K;

	++N, ++M;

	a[0][0] = 0;
	while (K--) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}

	for (int i = 1; i < N; ++i) a[i][0] = a[i-1][0] + 100;
	for (int i = 1; i < M; ++i) a[0][i] = a[0][i-1] + 100;

	for (int i = 1; i < N; ++i)
		for (int j = 1; j < M; ++j)
			if (a[i][j] == 1) {
				a[i][j] = min(a[i-1][j-1] + S, min(a[i-1][j]+100, a[i][j-1]+100));
			} else {
				a[i][j] = min(a[i-1][j]+100, a[i][j-1]+100);
			}

	cout << roundf(a[N-1][M-1]) << endl;

	return 0;
}

