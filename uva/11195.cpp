
#include <cmath>
#include <cstdio>
using namespace std;

#define uint unsigned int

#define N_MAX 15

int N, sol_num, a[N_MAX];

struct coord {
	int x, y;
} bads[N_MAX];
int bads_n;

void dfs(register int i, register uint row) {
	register int j;

	if (i == N) {
		++sol_num;
		return;
	}

	for (a[i] = 0; a[i] < N; ++a[i]) {
		for (j = 0; j < bads_n; ++j)
			if (bads[j].x == i && bads[j].y == a[i])
				break;
		if (j != bads_n)
			continue;

		// if row is not attacked
		if (row & 1<<a[i])
			continue;

		// check diagonally attacks
		for (j = 0; j < i; ++j)
			if (i-j == abs(a[i]-a[j]))
				break;

		if (i == j)
			dfs(i+1, row|(1<<a[i]));
	}
}

int x, y;
char line[N_MAX];

int main() {
	for (int test_i = 1; ; ++test_i) {
		/* prepare stage */
		sol_num = 0;
		bads_n = 0;

		/* input stage */
		scanf("%d", &N);
		if (N == 0)
			break;

		for (x = 0; x < N; ++x) {
			scanf("%s", line);
			for (y = 0; y < N; ++y) {
				if (line[y] == '*') {
					bads[bads_n].x = x;
					bads[bads_n].y = y;
					++bads_n;
				}
			}
		}

		dfs(0, 0);
		printf("Case %d: %d\n", test_i, sol_num);
	}

	return 0;
}

