
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1

struct tetrad {
	int a, b, c, d;

	tetrad(int aa, int ab, int ac, int ad)
		: a(aa)
		, b(ab)
		, c(ac)
		, d(ad)
	{}

	bool operator < (const tetrad & arg) const {
		if (a != arg.a) return a < arg.a; else
		if (b != arg.b) return b < arg.b; else
		if (c != arg.c) return c < arg.c; else
		return d < arg.d;
	}
};

#define a_MAX 201

int a, i, j, k, s;

const int cube_size = 290;
int cube[ cube_size ];

vector<tetrad> v;

int main() {
	for (i = 0; i < cube_size; ++i)
		cube[i] = i*i*i;

	for (i = 2; i < a_MAX; ++i) {
		for (j = i; j < a_MAX; ++j) {
			for (k = j; k < a_MAX; ++k) {
				s = cube[i] + cube[j] + cube[k];
				a = lower_bound(cube, cube+cube_size, s) - cube;

				if ( (a < cube_size) && (cube[a] == s) ) {
					v.push_back(tetrad(a, i, j, k));
				}
			}
		}
	}

	sort(v.begin(), v.end());

	for (
		vector<tetrad>::const_iterator it = v.begin();
		it < v.end();
		++it
	) {
		printf("Cube = %d, Triple = (%d,%d,%d)\n", it->a, it->b, it->c, it->d);
	}

	return 0;
}

