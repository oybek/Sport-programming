
#include <cmath>
#include <iostream>
using namespace std;

#define SOLUTION_BOUND 100

int soln;
int sol[ SOLUTION_BOUND ][ 9 ], cfg[9];

bool can_stand(int pos, int row) {
	for (int i = 1; i < pos; ++i) {
		if (cfg[i] == row) /* horizontal attack */
			return false;
		else
		if (abs(cfg[i]-row) == abs(i-pos)) /* diagonal attack */
			return false;
	}
	return true;
}

void backtrack(int pos) {
	if (pos == 9) {
		for (int i = 1; i <= 8; ++i)
			sol[ soln ][i] = cfg[i];
		++soln;

		return;
	}

	for (int i = 1; i <= 8; ++i) {
		if (can_stand(pos, i)) {
			cfg[pos] = i;
			backtrack(pos+1);
		}
	}
}

void gen_all_sols() {
	soln = 0;
	backtrack(1);

	cout << soln << endl;
	for (int i = 0; i < soln; ++i) {
		for (int j = 1; j <= 8; ++j) {
			cout << sol[i][j] << ' ';
		}
		cout << endl;
	}
}

int count_step(int * a, int i) {
	int n = 0;
	for (int j = 1; j <= 8; ++j)
		n += (sol[i][j] != a[j]);
	return n;
}

int main() {
	gen_all_sols();

	int tt = 1, a[9];
	while (cin	>> a[1] >> a[2] >> a[3] >> a[4]
				>> a[5] >> a[6] >> a[7] >> a[8]) {
		int min_st_n = 10000;
		for (int i = 0; i < soln; ++i) {
			min_st_n = min(min_st_n, count_step(a, i));
		}

		cout << "Case " << tt << ": " << min_st_n << endl;

		++tt;
	}

	return 0;
}

