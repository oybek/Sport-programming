
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 101

bool sign[ MAX_SIZE ] = {};
int m[ MAX_SIZE ][ MAX_SIZE ];

int main() {
	using namespace std;

	int n, t, i, j, k;

	// input part
	cin >> n >> k;
	for (; k--; sign[t] = 1) cin >> t;
	for (i = 1; i <= n; ++i)
	for (j = 1; j <= n; ++j)
		cin >> m[i][j];

	int tree_len = 0;
	for (i = 1; i <= n; ++i) {

		int a = -1, b = -1;

		// chose town which will be connected
		for (j = 1; j <= n; ++j) {

			if (sign[j] == true)
				for (k = 1; k <= n; ++k)
					if (sign[k] == false)
					if ((a == -1) || (m[j][k] < m[a][b])) {
						a = j;
						b = k;
					}
		}

		if (a == -1) {
			break;
		} else {
			sign[b] = true;
			tree_len += m[a][b];
		}
		//cout << tree_len << endl;
	}

	cout << tree_len << endl;

	return 0;
}

