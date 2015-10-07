
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

class fenwick_tree_3d {
	private:
		int size1, size2, size3;
		vector<vector<vector<int64> > > t;

	public:
		/* create and fill 3d array with zeroes */
		fenwick_tree_3d(int size1, int size2, int size3) {
			this->size1 = size1;
			this->size2 = size2;
			this->size3 = size3;

			t.resize(this->size1);
			for (int i = 0; i < size1; ++i) {
				t[i].resize(size2);
				for (int j = 0; j < size2; ++j) {
					t[i][j].resize(size3);
					for (int k = 0; k < size3; ++k) {
						t[i][j][k] = 0;
					}
				}
			}
		}

		/* It is unbelievable: O(log n) */
		int sum(int x, int y, int z) {
			int64 result = 0;
			for (int i = x; i >= 0; i = (i & (i+1)) - 1)
				for (int j = y; j >= 0; j = (j & (j+1)) - 1)
					for (int k = z; k >= 0; k = (k & (k+1)) - 1)
						result += t[i][j][k];
			return result;
		}

		/* O(log n) */
		void inc(int x, int y, int z, int delta) {
			for (int i = x; i < size1; i = (i | (i+1)))
				for (int j = y; j < size2; j = (j | (j+1)))
					for (int k = z; k < size3; k = (k | (k+1)))
						t[i][j][k] += delta;
		}

		/* O(log n) */
		int sum(int x1, int y1, int z1, int x2, int y2, int z2) {
			return sum(x2, y2, z2)
				- sum(x1-1,   y2,   z2)
				- sum(  x2, y1-1,   z2)
				- sum(  x2,   y2, z1-1)
				+ sum(x1-1, y1-1,   z2)
				+ sum(x1-1,   y2, z1-1)
				+ sum(  x2, y1-1, z1-1)
				- sum(x1-1, y1-1, z1-1);
		}
};

#define N_MAX 128

int main() {
	int N, M, x1, y1, z1, x2, y2, z2, delta;

	cin >> N;
	fenwick_tree_3d ftree(N, N, N);

	for (;;) {
		cin >> M;
		switch (M) {
			case 1:
				cin >> x1 >> y1 >> z1 >> delta;
				ftree.inc(x1, y1, z1, delta);
				break;

			case 2:
				cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
				cout << ftree.sum(x1, y1, z1, x2, y2, z2) << endl;
				break;

			case 3:
				return 0;
		}
	}

	return 0;
}

