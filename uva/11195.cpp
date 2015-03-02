
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

typedef unsigned int uint32;

using namespace std;

#define N_MAX 16

int N, soln;
bitset<N_MAX> attacked[N_MAX][N_MAX];

void place_queen(int x, int y) {
	attacked[x][x].set();
	for (int i = 0; i < N; ++i) {
		attacked[x][i].set(y);
		attacked[x][i].set(i);
		attacked[x][i].set(N-1-i);
	}
}

void backtrack(int x) {
	if (x == N) {
		++soln;
		return;
	}

	for (int y = 0; y < N; ++y) {
		if (!attacked[x][x][y])
	}
}

int main() {

	return 0;
}

